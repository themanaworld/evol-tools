;; Major mode for Evol Scripts in Emacs
;; Author: Joseph Botosh <rumly111@gmail.com>
;; Licence: GNU General Public Licence v3.0 (http://www.gnu.org/licenses/gpl-3.0.en.html)

(require 'cl)

(defgroup evol nil
  "Settings for evol-mode."
  :prefix "evol-"
  :group 'emacs)

(defcustom evol-all-dir ""
  "Directory containing server-code and server-data subdirectories"
  :group 'evol
  :type 'string)

(defvar evol-mode-constants nil "List of all Evol constants")
(defvar evol-mode-functions nil "List of Evol functions")
  
(defun evol-mode-parse-const-db (dbfile)
  (interactive "fPath to const.txt: ")
  (with-temp-buffer
    (message "Loading Evol constants from %s" dbfile)
    (insert-file-contents dbfile)
    (let ((constants))
      (while (not (eobp))
	(let ((line (buffer-substring-no-properties
		     (line-beginning-position)
		     (line-end-position)))
	      (constant))
	  (when (string-match "\\(^[A-Za-z][A-Za-z0-9_]*\\)[\t ]+\\([0-9]+\\)"
			      line)
	    (setq constant (substring line (match-beginning 1)
				      (match-end 1))
		  constants (cons constant constants))))
	(forward-line 1))
      constants)))

(defun evol-mode-parse-map-index-db (dbfile)
  (interactive "fPath to map_index.txt: ")
  (with-temp-buffer
    (insert-file-contents dbfile)
    (let ((maps))
      (while (not (eobp))
	(let ((line (buffer-substring-no-properties
		     (line-beginning-position)
		     (line-end-position)))
	      (map_))
	  (when (string-match
		 "\\(^[A-Za-z0-9][A-Za-z0-9_-]*[A-Za-z0-9]\\) \\([0-9]+\\)"
		 line)
	    (setq map_ (substring line (match-beginning 1)
				      (match-end 1))
		  maps (cons map_ maps))))
	(forward-line 1))
      maps)))

(defun evol-mode-parse-skill-db (dbfile)
  (interactive "fPath to skill_db.txt: ")
  (with-temp-buffer
    (insert-file-contents dbfile)
    (let ((skills))
      (while (not (eobp))
	(let ((line (buffer-substring-no-properties
		     (line-beginning-position)
		     (line-end-position)))
	      (skill))
	  (when (string-match
		 "^[1-9][0-9]*,\\([^,]+,\\)\\{14\\}[\t ]+\\([A-Za-z][A-Za-z0-9_]*[A-Za-z0-9]\\),"
		 line)
	    (setq skill (substring line (match-beginning 2)
				      (match-end 2))
		  skills (cons skill skills))))
	(forward-line 1))
      skills)))

(defun evol-mode-parse-mob-db (dbfile)
  (interactive "fPath to mob_db.txt: ")
  (with-temp-buffer
    (message "Loading mob_db from %s" dbfile)
    (insert-file-contents dbfile)
    (let ((mobs))
      (while (not (eobp))
	(let ((line (buffer-substring-no-properties
		     (line-beginning-position)
		     (line-end-position)))
	      (mob))
	  (when (string-match
		 "^[1-9][0-9]*,[\t ]+\\([A-Za-z]+\\),"
		 line)
	    (setq mob (substring line (match-beginning 1)
				      (match-end 1))
		  mobs (cons mob mobs))))
	(forward-line 1))
      mobs)))
      
(defun evol-mode-parse-item-db (dbfile)
  (interactive "fPath to item_db.txt: ")
  (with-temp-buffer
    (message "Loading item_db from %s" dbfile)
    (insert-file-contents dbfile)
    (let ((items))
      (while (not (eobp))
	(let ((line (buffer-substring-no-properties
		     (line-beginning-position)
		     (line-end-position)))
	      (item))
	  (when (string-match
		 "^[\t ]+AegisName:[\t ]+\"\\([A-Za-z]+\\)\""
		 line)
	    (setq item (substring line (match-beginning 1)
				      (match-end 1))
		  items (cons item items))))
	(forward-line 1))
      items)))

(defun evol-mode-parse-atcommand-c (cfile)
  (interactive "fPath to src/map/atcommand.c: ")
  (with-temp-buffer
    (message "Loading functions from from %s" cfile)
    (insert-file-contents cfile)
    (let ((commands))
      (while (not (eobp))
	(let ((line (buffer-substring-no-properties
		     (line-beginning-position)
		     (line-end-position)))
	      (cmd))
	  (when (string-match
		 "^[\t ]+ACMD_DEF(\\([a-z][a-z0-9]+\\))"
		 line)
	    (setq cmd (substring line (match-beginning 1)
				      (match-end 1))
		  commands (cons cmd commands)))
	  (when (string-match
		 "^[\t ]+ACMD_DEF2(\"\\([a-z][a-z0-9]+\\)\""
		 line)
	    (setq cmd (substring line (match-beginning 1)
				      (match-end 1))
		  commands (cons cmd commands))))
	(forward-line 1))
      commands)))

(defun evol-mode-parse-init-c (cfile)
  (interactive "fPath to evol/src/emap/init.c: ")
  (with-temp-buffer
    (message "Loading functions from from %s" cfile)
    (insert-file-contents cfile)
    (let ((commands))
      (while (not (eobp))
	(let ((line (buffer-substring-no-properties
		     (line-beginning-position)
		     (line-end-position)))
	      (cmd))
	  (when (string-match
		 "^[\t ]+addScriptCommand(\"\\([a-z][a-z0-9]+\\)\""
		 line)
	    (setq cmd (substring line (match-beginning 1)
				      (match-end 1))
		  commands (cons cmd commands))))
	(forward-line 1))
      commands)))

(defun evol-mode-parse-script-c (cfile)
  (interactive "fPath to src/map/script.c: ")
  (with-temp-buffer
    (message "Loading functions from from %s" cfile)
    (insert-file-contents cfile)
    (let ((commands))
      (while (not (eobp))
	(let ((line (buffer-substring-no-properties
		     (line-beginning-position)
		     (line-end-position)))
	      (cmd))
	  (when (string-match
		 "^BUILDIN(\\([a-z][a-z0-9]+\\))"
		 line)
	    (setq cmd (substring line (match-beginning 1)
				      (match-end 1))
		  commands (cons cmd commands))))
	(forward-line 1))
      commands)))


(defun evol-mode-setup-syntax-table ()
  (let ((st (standard-syntax-table)))
    (modify-syntax-entry ?_ "w" st)
    (modify-syntax-entry ?# "w" st)
    (modify-syntax-entry ?$ "w" st)
    (modify-syntax-entry ?@ "w" st)
    (modify-syntax-entry ?. "w" st)
    (modify-syntax-entry ?/ ". 124b" st)
    (modify-syntax-entry ?* ". 23" st)
    (modify-syntax-entry ?\n "> b" st)
    (set-syntax-table st)))

(defun evol-mode-setup-font-lock ()

  (defun make-regex-list (consts &optional max-length)
    (let ((result)
	  (len (length consts))
	  (start 0) (end)
	  (diff (or max-length 1000)))
      (while (< start len)
	(setq end (min (+ start diff) len))
	(push (subseq consts start end) result)
	(setq start (+ start diff)))
      result))

  (let ((evol-mode-functions-regex))
    (unless evol-mode-constants
      (setq evol-mode-constants
	  (append
	   (evol-mode-parse-const-db
	    (concat evol-all-dir "/server-data/db/const.txt"))
	   (evol-mode-parse-mob-db
	    (concat evol-all-dir "/server-data/db/re/mob_db.txt"))
	   (evol-mode-parse-skill-db
	    (concat evol-all-dir "/server-data/db/re/skill_db.txt"))
	   ;; (evol-mode-parse-map-index-db
	   ;; 	(concat evol-all-dir "/server-data/db/map_index.txt"))
	   (evol-mode-parse-item-db
	    (concat evol-all-dir "/server-data/db/re/item_db.conf"))
	   )))

    (unless evol-mode-functions
      (setq evol-mode-functions
	  (append
	   (list "mesq" "mesn")
	   (evol-mode-parse-script-c
	    (concat evol-all-dir "/server-code/src/map/script.c"))       
	   (evol-mode-parse-atcommand-c
	    (concat evol-all-dir "/server-code/src/map/atcommand.c"))
	   (evol-mode-parse-init-c
	    (concat evol-all-dir "/server-code/src/evol/src/emap/init.c")))))

    (let ((regex (regexp-opt evol-mode-functions 'words)))
      (font-lock-add-keywords 'evol-mode
			      `((,regex . font-lock-function-name-face))))

    (dolist (lst (make-regex-list (sort evol-mode-constants 'string-lessp)))
      (let ((rx (regexp-opt lst 'words)))
	(font-lock-add-keywords 'evol-mode
				`((,rx . font-lock-constant-face)))))))


(define-generic-mode evol-mode
  '("//" ("/*" . "*/"))
  '("break" "continue" "if" "else" "switch" "do" "for" "while"
    "function" "procedure" "script" "case")
  `(("\\(\"[^\"]+\"\\)"  1 font-lock-string-face)
    ("\\<\\(FIXME\\|TODO\\|BUG\\|NOTE\\):" 1 font-lock-warning-face)
    ("function[\t ]+\\([a-zA-Z][a-zA-Z0-9_]*\\)[\t\n ]{" 1 font-lock-function-name-face)
    ("\\<[0-9]+\\>" . font-lock-constant-face)
    ("[,;]" . font-lock-builtin-face)
    ;; ("^On\\(Init\\|Timer[0-9]+\\|Touch\\|\\(Minute\\|Hour\\)[0-9]\\{2\\}\\|Day[0-9]\\|\\(Day\\|Clock\\|Sun\\|Mon\\|Tue\\|Wed\\|Thu\\|Fri\\|Sat\\)[0-9]\\{4\\}\\|\\(Buy\\|Sell\\)Item\\|TimerQuit\\|InstanceInit\\|TouchNPC\\|\\(Count\\|Pay\\)Funds\\|PC\\(Die\\|Kill\\|Login\\|Logout\\|LoadMap\\|BaseLvUp\\|JobLvUp\\)Event\\):" . font-lock-constant-face)
    ("^[A-Za-z][A-Za-z0-9_]+:" . font-lock-constant-face)
    ("\\<\\(@\\|$\\|$@\\|.\\|.@\\|'\\|#\\|##\\)\\([a-zA-Z][a-zA-Z0-9_]*\\)$\\{0,1\\}\\>" . font-lock-variable-name-face)
    )
  nil
  ;; nil
  '(evol-mode-setup-font-lock
    evol-mode-setup-syntax-table
    (lambda () (setq indent-tabs-mode nil)))
  "Major mode for syntax highlighting of Evol Scripts")

(add-to-list 'magic-mode-alist '("^// Evol scripts." . evol-mode))

(provide 'evol-mode)
