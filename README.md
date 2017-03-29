# 21SH

This project is the reproduction of a shell. I had to implement lot of features.
The mind is to make it from scratch.
This is a solo project.

#### Builtins :
		env:
			env [-i][ENV_VAR_NAME=][ENV_VALUE][CMD]
		setenv:
			setenv [ENV_NAME_VAR] [ENV_VALUE]
		unsetenv:
			unsetenv [NAME_VAR]
		envreset:
			enreset -- reset env with start shell env configuration
		exit:
			exit [VALUE]
		history:
			history [VALUE] -- Value print n_VALUE last command in history
		cd:
			cd [-LP] [PATH]
				PATH:		absolute path:	/path
										~
						relative path:	./path
										~/path
						direct path:	($PWD)path
										'-'
				OPTIONS :	Options can be print everywhere in the command.
						For disable them you can use "--"

		echo:
			echo [-Een] [--version] [--help] [ARG]
				You can print characters with them OCTAL or HEXA values with -e option 
				Cf "man echo"

#### Pipe: '|'
	CMD | CMD
		You can it to use all of available pipe else shell return error. Test: "CMD | CMD | CMD | CMD ..." 
		There is no limit of buffer usage; Test : ls -Rla | cat -e

#### Separator: ;
	You can write mutiple command and separate them with ';' 
	CMD ; CMD

#### Redirections: < > << >> :
		Heredoc: <<
			Multiple enter for Heredoc are valid but just the last one will be used 
			Waiting Current Keyword is print in prompt 

#### Groups : []{}()
		Those parts will be delete before execution 
		Waiting close character is print in prompt 
		To much open character make a warning 

#### Quotes: "" '' ``
		For "" and '', it's the current usage 
		The `` are like the "" but they resolve "" as simple character instead of quotes 

#### Variables: $VARIABLE
		Call $ENV_NAME_VAR with '$' for replace it by his ENV_VALUE 

#### BackSlash: \
		Use it for echap a character
		if \ is the last one of a command, the shell return the line and let you continue write your command 

#### Operator: && ||
		AND operator &&: If the first command return SUCCESS then the second command is execute else not.  
		OR operator ||:	 If the first command return ERROR then the second command is execute else not.  

#### Agregator File Descriptor: [number]>&[number] , 2>&1 ...
		Simple agreg_fd.
			[number] are strictly necessary.
		Just the first one valid agreg_fd will be use.

#### Commentary: \#
		You can use # for insert commentary at the end of your command
		Every characters write after # will be a commentary

### TERMCAPS:

	left arrow	: Move to one left character
	right arrow : Move to one right character
	up arrow	: Print previous command history
	down arrow	: Print next command history

	enter		: Valid command
	delete		: Delete one character on the right of cursor 
	suppr		: Delete one character on the left of cursor

	CTRL +:
		k	: Cut the line after the cursor
		u	: Cut all the line
		w	: Paste the last cut
		e	: Go to the end of the command
		a	: Go to the begin of the command

		d	: Exit the shell
		l	: Clear the window

		s	: Suspend the current command
		q	: Start the command previously suspend 
		c	: Stop the current command
		z	: Not available

	CTRL + MAJ + \	: Quit

	ALT +:
		left arrow	: Move to one left word
		right arrow 	: Move to one right word
		up arrow	: Move to one line up
		down arrow	: Move to one line down

	BL : Bell signal when Termcaps are unvailable.

	You can resize the window reasonably. :D
	If Termcap seems broken, use CTRL + l for clean the bugs 

#### $SHLVL:
	Incremente SHLVL env variable for each new shell inception. 

#### Finest Error Management:
	For the majority of error, they have precise error return. 

##### No leaks

##### MAKEFILE:
	Debug mode:
		Not available in the final project with norminette because it needs to 
		be protected by double inclusion
		For use it, compile with "make db"
		If the project is compiled yet, use "make rdb"


### BUGS : 
1. cat bad_file > fichier 2>&1
	If you try to use an agregator of file descriptor with __cat__ and that the file in parameter of cat does not exist the error output stay on the file. So the file descriptor is not restored. Next outputs have some troubles.
	
2. One leak with "env + binary" in a very particulary case.


### Grade : 111/100
