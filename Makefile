palindrome_prod: 
	g++ -std=c++14 -g -Wall -o palindrome_prod main_palindrome_prod.cc palindrome_prod.cc

clean: 
	rm output.txt palindrome_prod

palindrome_prod_exercise:
	g++ -std=c++14 -g -Wall -o palindrome_prod_exercise main_palindrome_prod_exercise.cc palindrome_prod.cc
