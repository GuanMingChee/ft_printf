*This project has been created as part of the 42 curriculum by gchee.*


- **Description**
	- This project serves the purpose of understanding printf and variadic functions.
	- We will replicate the function of printf (which is to handle the conversion of cspdiuxX% specifiers)

- **Instructions**
	- To test manually: 
		- Run the commands below in ft_printf directory to compile the ft_printf function, compile it with manually written test cases, then execute it.
			```
			make
			cc -Wall -Wextra -Werror <Manual_Testcase>.c libftprintf.a -o <executable>
			./<executable>
			```
	- To test with pre-written test cases:
		- Refer to the tester in "Resources" section for more details. Note that valgrind is needed for this.
			`
			sudo apt update && sudo apt install -y valgrind
			`

- **Resources**
	- [Pre-written tester](https://github.com/Tripouille/printfTester)
	- [Makefile resource](https://makefiletutorial.com/#variables)
	- AI usage:
		- understand each specifier better to reduce the number of functions
		- understand variadic functions better with more personalized explanation with examples
		- troubleshoot blockers to clarify thoughts
		- help to plan the algorithm
