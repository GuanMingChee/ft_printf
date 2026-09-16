*This project has been created as part of the 42 curriculum by gchee.*


- **Description**
	- This project serves the purpose of understanding printf and variadic function.
	- We will replicate the function of printf (which is to handle the conversion of cspdiuxX% specifiers)

- **Instructions**
	- To test manually: 
		- Run command below to compile the ft_printf function, compile it with manual written testcases then exceute it.
			```
			make
			cc -Wall -Wextra -Werror <Manual_Testcase>.c libftprintf.a -o <executable>
			./<executable>
			```
	- To test with pre-written testcases:
		- Refer to tester in "Resource" section for more details. Be aware that valgrind is needed for this.
			`
			sudo apt update && sudo apt install -y valgrind
			`

- **Resources**
	- [Pre-written tester](https://github.com/Tripouille/printfTester)
	- [Makefile resource](https://makefiletutorial.com/#variables)
	- AI usage:
		- understand each specifiers better to reduce number of functions
		- understand variadic function better with more personalized explanation with examples
		- troubleshoot blockers to clarify thoughts
		- help to plan algorithm
