;;;; -*- Mode: Lisp; -*-
;;
;; AUTHORS: TEAM MEMBERS:Jacob Chandler & Rajatvir Singh
;;
;; This is a version of the bingo code that is written in a
;; style that is more functional than procedural in nature.
;;

(defun read-int-line (str)
  "Reads one line from stream STR, and returns a list of the integers parsed from the line."
  (mapcar #'parse-integer (delete-if #'(lambda (x) (equal x ""))  (split-sequence " " (read-line str)))))

(defun bingo-data (str)
  "Returns a list of three items: a 2D pattern array, a list of called numbers, and a 2D player card, in that order."
  (nconc (list (make-array '(5 5) :initial-contents (loop for i from 0 to 4 collecting (read-int-line str))))
         (read-int-line str) ;; eat up empty line
         (list (read-int-line str))
         (read-int-line str) ;; eat up empty line
         (list (make-array '(5 5) :initial-contents (loop for i from 0 to 4 collecting (read-int-line str))))))

;;-----------------------------------------------------------------------

(defun check-if-on-board (pat i j)
  (or (= (aref pat i j) 1) (= (aref pat i j) 4)))

(defun if-there-mark (bd nums i j)
  (or (= (aref bd i j) 0) (member (aref bd i j) nums)))

(defun bingo-present (pattern numbers board) 
  (let ((bingo t))
    (loop for i from 0 to 4 doing 
          (loop for j from 0 to 4 doing
                (if (and (check-if-on-board pattern i j)
                         (not (if-there-mark board numbers i j)))
                    (setf bingo nil))))
    bingo))

(defun crazypattern (p)
  (let ((crazy nil))
    (loop for i from 0 to 4 doing 
          (loop for j from 0 to 4 doing 
                (when (= (aref p i j) 4)
                  (setf crazy t))))
    crazy))


;;------------------------------------------------------------------------


(defun rotate90(p)
  (let ((new-matrix(make-array '(5 5) :initial-element nil))
        (n 5))
    (loop for i below (/ n 2) doing 
          (loop for j from i to (- (- n i) 1) doing
                (setf (aref new-matrix i j) (aref p (- (- n 1) j) i))
                (setf (aref new-matrix (- (- n 1) j) i) (aref p (- (- n 1) i) (- (- n 1) j)))
                (setf (aref new-matrix (- (- n 1) i) (- (- n 1) j)) (aref p j (- (- n 1) i)))
                (setf (aref new-matrix j (- (- n 1) i)) (aref p i j))))
    new-matrix))

(defun print-matrix (m)
  "Prints out the 5x5 matrix M in a pretty format."
  (loop for i below 5 doing
        (loop for j below 5 doing
              (format t "~2D " (aref m i j)))
        (format t "~%"))
  (format t "~%"))



(defun verify-bingo-data (pattern numbers board)
  (if (not (crazypattern pattern))
      (bingo-present pattern numbers board)
      (let ((pat pattern)
            (bingo nil))
        (loop for i from 0 to 3 doing 
              (when (bingo-present pat numbers board)
                (setf bingo t))
              (setf pat (rotate90 pat)))
        bingo)))




(defun verify (&optional (str *standard-input*))
"This is what gets called to handle data copied and pasted to STDIN, and prints out correct results."
  (if (apply #'verify-bingo-data (bingo-data str))
      (progn
        (format t "VALID BINGO~%")
        t)
      (progn
        (format t "NO BINGO~%")
        nil)))
