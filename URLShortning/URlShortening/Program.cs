using System;
using System.IO;
using System.Text;

namespace URlShortening
{
	class Program
	{
		static StreamWriter outputFile = new StreamWriter(Path.Combine("WriteLines.txt"));

		public static FileStream filestream; //= new FileStream("output.txt", FileMode.OpenOrCreate);
		static void Main(string[] args)
		{
			char[] set1 = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
			int k = 6;
			filestream = new FileStream("output.txt", FileMode.OpenOrCreate);
			printAllKLength(set1, k);

		}
		static void printAllKLength(char[] set, int k)
		{
			int n = set.Length;
			printAllKLengthRec(set, "", n, k);
		}

		static UInt64 count = 1;

		static void printAllKLengthRec(char[] set,
									   String prefix,
									   int n, int k)
		{
			if (k == 0)
			{
				count++;
				outputFile.WriteLine(prefix);
				filestream.Write(Encoding.ASCII.GetBytes(prefix), 0, 0);
				if (count % 1000 == 0)
					filestream.Flush();
				return;
			}

			for (int i = 0; i < n; ++i)
			{
				String newPrefix = prefix + set[i];
				printAllKLengthRec(set, newPrefix, n, k - 1);
			}
		}
	}
}
