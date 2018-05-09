;;; .dir-locals.el --

;;; Commentary:

;;; Code:
((c++-mode .
      ((eval  . (progn
                  (require 'rtags-init)
                  (require 'irony-mode-init)
                  (let ((includes-list (list
                                        (substitute-in-file-name "$rcsw/include")
                                        (concat (projectile-project-root) "include")
                                        )))
                    (setq flycheck-clang-include-path includes-list)
                    (add-to-list 'flycheck-clang-args "-fPIC")
                    (add-to-list 'flycheck-clang-definitions "HAL_CONFIG=HAL_CONFIG_ARGOS_FOOTBOT")
                    (add-to-list 'flycheck-clang-args "-std=c++14")
                    (setq flycheck-gcc-include-path includes-list)
                    (add-to-list 'flycheck-gcc-args "-fPIC")
                    (add-to-list 'flycheck-gcc-args "-std=c++14")
                    (add-to-list 'flycheck-gcc-definitions "HAL_CONFIG=HAL_CONFIG_FOOTBOT")

                    (setq compile-command (concat "make -C" (concat (projectile-project-root) "build")))
                    (add-hook 'c++-mode-hook 'google-style-hook)
                    )
                  (let ((cc-search-dirs (list (concat (projectile-project-root) "include/rcppsw/*/*")
                                              (concat (projectile-project-root) "src/*/*/src/*")
                                              (concat (projectile-project-root) "include"))
                                        ))
                    (setq cc-search-directories cc-search-dirs))
                  (c++-mode)
              )
         ))
      ))

;;; end of .dir-locals.el
