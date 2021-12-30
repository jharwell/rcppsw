;;; .dir-locals.el --

;;; Commentary:

;;; Code:
((c++-mode .
      ((eval  . (progn
                  (let ((includes-list (list
                                        (substitute-in-file-name "$rcsw/include")
                                        (concat (projectile-project-root)
                                                "include")
                                        "/usr/include/lua5.2"
                                        )))
                    (setq flycheck-clang-include-path includes-list)
                    (add-to-list 'flycheck-clang-args "-fPIC")
                    (add-to-list 'flycheck-clang-args "-std=c++17")
                    (add-to-list 'flycheck-clang-args (concat "-isystem" (substitute-in-file-name
                                                                          "$rcppsw")))
                    (add-to-list 'flycheck-clang-args (concat "-isystem" (substitute-in-file-name
                                                                          "$localroot/include")))


                    (setq flycheck-gcc-include-path includes-list)
                    (add-to-list 'flycheck-gcc-args "-fPIC")
                    (add-to-list 'flycheck-gcc-args "-std=c++17")
                    (let ((cc-search-dirs (list (concat (projectile-project-root) "include/rcppsw/*/*")
                                                (concat (projectile-project-root) "src/*/*")
                                                (concat (projectile-project-root) "include"))
                                          ))
                      (setq cc-search-directories cc-search-dirs))
                    )
              )
         ))
      ))

;;; end of .dir-locals.el
