#pragma once

using namespace System::Windows::Forms;

public ref class MCode
{
   public:
      MCode()
	  {
		  charMap  = gcnew System::Collections::Generic::Dictionary<char, System::String^>();
		  morseMap = gcnew System::Collections::Generic::Dictionary<System::String^, char>();

		  charMap['0'] = "-----";  morseMap["-----"] = '0';
		  charMap['1'] = ".----";  morseMap[".----"] = '1';
		  charMap['2'] = "..---";  morseMap["..---"] = '2';
		  charMap['3'] = "...--";  morseMap["...--"] = '3';
		  charMap['4'] = "....-";  morseMap["....-"] = '4';
		  charMap['5'] = ".....";  morseMap["....."] = '5';
		  charMap['6'] = "-....";  morseMap["-...."] = '6';
		  charMap['7'] = "--...";  morseMap["--..."] = '7';
		  charMap['8'] = "---..";  morseMap["---.."] = '8';
		  charMap['9'] = "----.";  morseMap["----."] = '9';

		  charMap['A'] = ".-";     morseMap[".-"]    = 'A';
		  charMap['a'] = ".-";     morseMap[".-"]    = 'a';
		  charMap['B'] = "-...";   morseMap["-..."]  = 'B';
		  charMap['b'] = "-...";   morseMap["-..."]  = 'b';
		  charMap['C'] = "-.-.";   morseMap["-.-."]  = 'C';
		  charMap['c'] = "-.-.";   morseMap["-.-."]  = 'c';
		  charMap['D'] = "-..";    morseMap["-.."]   = 'D';
		  charMap['d'] = "-..";    morseMap["-.."]   = 'd';
		  charMap['E'] = ".";      morseMap["."]     = 'E';
		  charMap['e'] = ".";      morseMap["."]     = 'e';
		  charMap['F'] = "..-.";   morseMap["..-."]  = 'F';
		  charMap['f'] = "..-.";   morseMap["..-."]  = 'f';
		  charMap['G'] = "--.";    morseMap["--."]   = 'G';
		  charMap['g'] = "--.";    morseMap["--."]   = 'g';
		  charMap['H'] = "....";   morseMap["...."]  = 'H';
		  charMap['h'] = "....";   morseMap["...."]  = 'h';
		  charMap['I'] = "..";     morseMap[".."]    = 'I';
		  charMap['i'] = "..";     morseMap[".."]    = 'i';
		  charMap['J'] = ".---";   morseMap[".---"]  = 'J';
		  charMap['j'] = ".---";   morseMap[".---"]  = 'j';
		  charMap['K'] = "-.-";    morseMap["-.-"]   = 'K';
		  charMap['k'] = "-.-";    morseMap["-.-"]   = 'k';
		  charMap['L'] = ".-..";   morseMap[".-.."]  = 'L';
		  charMap['l'] = ".-..";   morseMap[".-.."]  = 'l';
		  charMap['M'] = "--";     morseMap["--"]    = 'M';
		  charMap['m'] = "--";     morseMap["--"]    = 'm';
		  charMap['N'] = "-.";     morseMap["-."]    = 'N';
		  charMap['n'] = "-.";     morseMap["-."]    = 'n';
		  charMap['O'] = "---";    morseMap["---"]   = 'O';
		  charMap['o'] = "---";    morseMap["---"]   = 'o';
		  charMap['P'] = ".--.";   morseMap[".--."]  = 'P';
		  charMap['p'] = ".--.";   morseMap[".--."]  = 'p';
		  charMap['Q'] = "--.-";   morseMap["--.-"]  = 'Q';
		  charMap['q'] = "--.-";   morseMap["--.-"]  = 'q';
		  charMap['R'] = ".-.";    morseMap[".-."]   = 'R';
		  charMap['r'] = ".-.";    morseMap[".-."]   = 'r';
		  charMap['S'] = "...";    morseMap["..."]   = 'S';
		  charMap['s'] = "...";    morseMap["..."]   = 's';
		  charMap['T'] = "-";      morseMap["-"]     = 'T';
		  charMap['t'] = "-";      morseMap["-"]     = 't';
		  charMap['U'] = "..-";    morseMap["..-"]   = 'U';
		  charMap['u'] = "..-";    morseMap["..-"]   = 'u';
		  charMap['V'] = "...-";   morseMap["...-"]  = 'V';
		  charMap['v'] = "...-";   morseMap["...-"]  = 'v';
		  charMap['W'] = ".--";    morseMap[".--"]   = 'W';
		  charMap['w'] = ".--";    morseMap[".--"]   = 'w';
		  charMap['X'] = "-..-";   morseMap["-..-"]  = 'X';
		  charMap['x'] = "-..-";   morseMap["-..-"]  = 'x';
		  charMap['Y'] = "-.--";   morseMap["-.--"]  = 'Y';
		  charMap['y'] = "-.--";   morseMap["-.--"]  = 'y';
		  charMap['Z'] = "--..";   morseMap["--.."]  = 'Z';
		  charMap['z'] = "--..";   morseMap["--.."]  = 'z';

		  charMap[' '] = " ";      morseMap[" "]  = ' ';
		                           morseMap["  "] = ' ';
	  }

      ~MCode()
	  {
	  }

	  System::String^ operator[]( char c )
	  {
		 System::String^ str = gcnew System::String( "" );
		 if( charMap->TryGetValue( c, str ) )
		 {
		    return charMap[c];
		 }
		 else
		 {
			 return " ";
		 }
	  }

	  char operator[]( System::String^ text )
	  {
		 char c = 0;
		 if( morseMap->TryGetValue( text, c ) )
		 {
		    return morseMap[text];
		 }
		 else
		 {
			 return ' ';
		 }
	  }

	  System::String^ ConvertToMorseCode( System::String^ text )
	  {
		  System::String^ MorseCodeString = gcnew System::String( "" );
		  for( int i=0; i<text->Length; i++ )
		  {			  
			 System::String^ str = gcnew System::String( "" );
			 if( charMap->TryGetValue( (char)text[i], str ) )
			 {
			    MorseCodeString += charMap[ (char)text[i] ]+" ";
			 }
			 else
			 {
				MorseCodeString += " ";
			 }
		  }
		  return MorseCodeString;
	  }

	  System::String^ ConvertToAscii( System::String^ text )
	  {
		  text = StripNonMorseCharacters( text );
		  array< System::String^ >^ morse_array = text->Split( ' ' );

		  System::String^ AsciiString = gcnew System::String( "" );
		  for( int i=0 ; i<morse_array->Length ; i++ )
		  {			  
			 char c = 0;
			 if( morseMap->TryGetValue( morse_array[i], c ) )
			 {
				 AsciiString += gcnew System::String( (char)morseMap[ morse_array[i] ], 1 );// + " ";
			 }
			 else
			 {
				AsciiString += " ";
			 }
		  }
		  return AsciiString;
	  }

	  System::String^ StripNonMorseCharacters( System::String^ text )
	  {
		  System::String^ morsecharacters = gcnew System::String( "" );
		  for( int i=0 ; i<text->Length ; i++ )
		  {
			  if( text[i] != '-' && text[i] != ' ' && text[i] != '.' )
			  {
                 continue;
			  }
			  else
			  {
				  morsecharacters += text[i];
			  }
		  }
		  return morsecharacters;
	  }
	  bool IsMorse( wchar_t c )
	  {
		  if( c != '-' && c != '.' && c != ' ' )
		  {
			  return false;
		  }
		  return true;
	  }

	  System::Collections::Generic::Dictionary<char, System::String^>^ charMap;
  	  System::Collections::Generic::Dictionary<System::String^, char>^ morseMap;
};
