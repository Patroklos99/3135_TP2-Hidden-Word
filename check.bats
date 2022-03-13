prog=motcache
arg=entree.txt
# Normal usage

@test "test0 : tester q" {
   #skip
   run ./$prog
   [ "${lines[0]}" = "Argument manquant" ]
   }

@test "test1 : tester c" {
    #skip
    run ./$prog $arg
    [ "${lines[0]}" = "PRESIDENTKENNEDY" ]
}






