using System;
using System.Collections.Generic;
using System.Text;

namespace Targil_12_TestCase
{
    public class SentenceUtils
    {
        public static string ToTitleCase(string sentence)
        {
            sentence = sentence + " ";
            String newSentence = "";
            String temp = "";
            int k = 0;

            for (int i = 0; i < sentence.Length; i++)
			{
                if(sentence[i] == ' ')
				{
                    temp = char.ToUpper(sentence[k]) + sentence.Substring(k + 1, i - k).ToLower();
                    k = i + 1;
                    newSentence += temp;
                    temp = "";
                }
			}

            return newSentence.Substring(0 , newSentence.Length - 1);
        }
    }

}
