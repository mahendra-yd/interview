using System.Text;

namespace PersonRepositry.Interface
{
	public class Person
	{

		public string FName { get; set; }
		public string LName { get; set; }
		public int Age { get; set; }
		public override string ToString()
		{
			StringBuilder builder = new StringBuilder();
			builder.AppendFormat("Fisrt Name {0} Last Name {1} Age {2}", FName, LName, Age);
			return builder.ToString();
		}
	}
}
