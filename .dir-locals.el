;;; .dir-locals.el --

;;; Commentary:

;;; Code:
((c++-mode .
      ((eval  . (progn
                  (let ((includes-list (list
                                        (substitute-in-file-name "$rcsw/include")
                                        (concat (projectile-project-root) "include")
                                        )))
                    (setq flycheck-clang-include-path includes-list)
                    (add-to-list 'flycheck-clang-args "-fPIC")
                    (add-to-list 'flycheck-clang-definitions "HAL_CONFIG=HAL_CONFIG_ARGOS_FOOTBOT")
                    (add-to-list 'flycheck-clang-args "-std=c++14")
                    (add-to-list 'flycheck-clang-args (concat "-isystem" (substitute-in-file-name
                                                                          "$rcppsw")))
                    (add-to-list 'flycheck-clang-args (concat "-isystem" (substitute-in-file-name
                                                                          "$localroot/include")))


                    (setq flycheck-gcc-include-path includes-list)
                    (add-to-list 'flycheck-gcc-args "-fPIC")
                    (add-to-list 'flycheck-gcc-args "-std=c++14")
                    (add-to-list 'flycheck-gcc-definitions "HAL_CONFIG=HAL_CONFIG_FOOTBOT")
                    )
                  (c++-mode)
              )
         ))
      ))

;;; end of .dir-locals.el
