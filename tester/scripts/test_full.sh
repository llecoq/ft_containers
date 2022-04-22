echo "		           STD"
echo "*--------------------------------------------------------*"
make clean
echo "compiling ..."
make DFLAGS=-Dstd_lib=1
echo "map ft execution time :"
/usr/bin/time ./ft_containers map > tester/tester_results/map_std.test
echo "pair std execution time :"
/usr/bin/time ./ft_containers pair > tester/tester_results/pair_std.test
echo "set std execution time :"
/usr/bin/time ./ft_containers set > tester/tester_results/set_std.test
echo "stack std execution time :"
/usr/bin/time ./ft_containers stack > tester/tester_results/stack_std.test
echo "vector std execution time :"
/usr/bin/time ./ft_containers vector > tester/tester_results/vector_std.test
echo "		         STD DONE"
echo "*--------------------------------------------------------*"

echo "		           FT"
echo "*--------------------------------------------------------*"
make clean 
echo "compiling ..."
make DFLAGS=-Dstd_lib=0
echo "map ft execution time :"
/usr/bin/time ./ft_containers map > tester/tester_results/map_ft.test
echo "pair ft execution time :"
/usr/bin/time ./ft_containers pair > tester/tester_results/pair_ft.test
echo "set ft execution time :"
/usr/bin/time ./ft_containers set > tester/tester_results/set_ft.test
echo "stack ft execution time :"
/usr/bin/time ./ft_containers stack > tester/tester_results/stack_ft.test
echo "vector ft execution time :"
/usr/bin/time ./ft_containers vector > tester/tester_results/vector_ft.test
echo "		         FT DONE"
echo "*--------------------------------------------------------*"
echo "diff map:"
diff tester/tester_results/map_ft.test tester/tester_results/map_std.test
echo "diff pair:"
diff tester/tester_results/pair_ft.test tester/tester_results/pair_std.test
echo "diff set:"
diff tester/tester_results/set_ft.test tester/tester_results/set_std.test
echo "diff stack:"
diff tester/tester_results/stack_ft.test tester/tester_results/stack_std.test
echo "diff vector:"
diff tester/tester_results/vector_ft.test tester/tester_results/vector_std.test