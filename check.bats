prog=motcache
arg=entree.txt
nom=""
# Normal usage

@test "test0 : sans aucune entree, affichage d'erreur" {
   #skip
   run ./$prog
   [ "${lines[0]}" = "Argument manquant" ]
   }

}

@test "test1 : Trop d'arguments" {
    #skip
    run ./$prog $arg $arg
    [ "${lines[0]}" = "Trop d'arguments" ]
}





