echo "		           MAP"
echo "*--------------------------------------------------------*"
echo "map std execution time :"
make clean
make DFLAGS=-Dstd_lib=1
/usr/bin/time ./ft_containers map > tester/tester_results/map_std.test
echo "map ft execution time :"
make clean 
make DFLAGS=-Dstd_lib=0
/usr/bin/time ./ft_containers map > tester/tester_results/map_ft.test
echo "diff :"
diff tester/tester_results/map_ft.test tester/tester_results/map_std.test
echo "		         MAP DONE"
echo "*--------------------------------------------------------*"
# leaks -atExit -- ./ft_containers ft vector