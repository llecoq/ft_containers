echo "		           PAIR"
echo "*--------------------------------------------------------*"
echo "pair std execution time :"
/usr/bin/time ./ft_containers std pair > tester/tester_results/pair_std.test
echo "pair ft execution time :"
/usr/bin/time ./ft_containers ft pair > tester/tester_results/pair_ft.test
echo "diff :"
diff tester/tester_results/pair_ft.test tester/tester_results/pair_std.test
echo "		         PAIR DONE"
echo "*--------------------------------------------------------*"
# leaks -atExit -- ./ft_containers ft vector