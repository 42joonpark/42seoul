# colors
Black='\033[0;30m'
Red='\033[0;31m'
Green='\033[0;32m'
Yellow='\033[1;33m'
Blue='\033[0;34m'
Purple='\033[0;35m'
Cyan='\033[0;36m'
White='\033[1;37m'
NC='\033[0m'

check_norminette()
{
	for file in *.c; do
		if [[ $(norminette "$file" | grep "Error") ]]; then
			return 0
		else
			printf "${Green}.${NC}";
		fi
	done
	return 1
}

check_mandatory()
{
	declare -a problem=(
			'./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e'
			'./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 3" | cat -e'
			)
	declare -a answer=(
			'1 2 3 4$\n2 3 4 1$\n3 4 1 2$\n4 1 2 3$'
			'Error$'
			)

	len=${#problem[@]}
	for (( i=0; i<len; i++ ));
		do
			RESULT=$(eval ${problem[i]})
			if [[ "$RESULT" == ${answer[i]} ]]; then
				echo "RIGHT"
			else
				echo "WRONG"
			fi
		done
}

# go to directory
cd ex00

# Norm Test
printf "${Cyan}norminette(y/n): "
read input
if [[ "$input" == "y" || "$input" == "yes" || "$input" == "Y" ]]; then
	printf "${Purple}*** [Norminette Check] ***${NC}\n"
	check_norminette
	CHECK_NORM_RESULT=$?
	if [ "$CHECK_NORM_RESULT" -eq "1" ]; then
		printf "\n${Green}Norminette check success.\n${NC}"
	else
		printf "${Red}Norminette check failed.\n${NC}"
		exit	1
	fi
fi

# Compile
printf "${Cyan}compile(y/n): "
read input
if [[ "$input" == "y" || "$input" == "yes" || "$input" == "Y" ]]; then
	printf "${Purple}*** [Compile] ***${NC}\n"
	gcc -Wall -Werror -Wextra -o rush-01 *.c
	if [ $? -ne 0 ]; then
		printf "${Red}Compile Failed.\n${NC}"
		exit	1
	else
		printf "${Blue}Compile Success.\n${NC}"
	fi
fi

# Test
printf "${Cyan}test(mand/bonus): "
read test

if [[ "$test" == "mand" || "$test" == "mandatory" ]]; then
	# Mandatory Test
	printf "${Purple}*** [Mandatory Test] ***${NC}\n"
	check_mandatory
else
	printf "${Purple}*** [Bonus Test] ***${NC}\n"
fi
