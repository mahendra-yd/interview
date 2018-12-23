namespace Polygen.Library
{
	public class Octagen : IRegularPolygen
	{
		public int NumberOfSide { get; set; }
		public int SideLength { get; set; }
		public Octagen(int _sideLenght)
		{
			NumberOfSide = 8;
			SideLength = _sideLenght;

		}
		public double GetArea()
		{
			return 4 * SideLength * NumberOfSide;
		}

		public double GetPerimeter()
		{
			return NumberOfSide * SideLength;
		}
	}
}
