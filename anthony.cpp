bool getQuotedString(string& line, int &index, string& subString) {
	subString = "";
	if (index == 0) {
		index++;
	}
	else {
		index += 3;
	}
	
	while (index < line.size() && line[index] != '\"') {
		subString += line[index];
		index++;
	}
	return index < line.size() - 1;
}
