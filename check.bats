prog=motcache
arg=entree.txt
nom=""
# Normal usage

@test "test0 : sans aucune entree, affichage d'erreur" {
   #skip
   run ./$prog
   [ "${lines[0]}" = "Argument manquant" ]
<<<<<<< HEAD
=======
   }

>>>>>>> 399b217e1ae1bf5a6746d1458a82dc7899038166
}

@test "test1 : Trop d'arguments" {
    #skip
    run ./$prog $arg $arg
    [ "${lines[0]}" = "Trop d'arguments" ]
}





