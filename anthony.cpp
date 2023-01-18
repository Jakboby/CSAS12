bool getQuotedString(string& line, int &index, string& subString) {
	subString = "";
	index++;
	while (line[index] != '\"') {
		subString += line[index];
		index++;
	}
	return index == line.size() - 1;
}
