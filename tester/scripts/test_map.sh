echo "		           MAP"
echo "*--------------------------------------------------------*"
make clean
echo "compiling ..."
make DFLAGS=-Dstd_lib=1
echo "map std execution time :"
/usr/bin/time ./ft_containers map > tester/tester_results/map_std.test
make clean 
echo "compiling ..."
make DFLAGS=-Dstd_lib=0
echo "map ft execution time :"
/usr/bin/time ./ft_containers map > tester/tester_results/map_ft.test
echo "diff :"
diff tester/tester_results/map_ft.test tester/tester_results/map_std.test
echo "		         MAP DONE"
echo "*--------------------------------------------------------*"
# leaks -atExit -- ./ft_containers ft vector