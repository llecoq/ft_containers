mkdir -p tester/tester_results
make std > tester/tester_results/std.test
./ft_containers > tester/tester_results/std.test
make ft > tester/tester_results/ft.test
./ft_containers > tester/tester_results/ft.test
echo "diff :"
diff tester/tester_results/ft.test tester/tester_results/std.test