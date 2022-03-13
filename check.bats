prog=motcache
arg=entree.txt
nom=""
# Normal usage

@test "test0 : sans aucune entree, affichage d'erreur" {
   #skip
   run ./$prog
   [ "${lines[0]}" = "Argument manquant" ]
   }

@test "test1 : tester c" {
    #skip
    run ./$prog $arg
    [ "${lines[0]}" = "PRESIDENTKENNEDY" ]
}

@test "test2 : Trop d'arguments" {
    #skip
    run ./$prog $arg $arg
    [ "${lines[0]}" = "Trop d'arguments" ]
}





