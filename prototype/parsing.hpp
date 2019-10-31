int parseUserInput(string input) {
	//FIXME if user input includes spaces in some string, those spaces will be counted as multiple inputs.
	int parsedInput = 0;
	for(unsigned i = 0; i < input.size(); ++i) {
		if(input[i] == ' ') {
			++parsedInput;
		}
	}
	return parsedInput;
}
