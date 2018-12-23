namespace Polygen.Library
{
	/// <summary>
	/// This class is used for dmeo of interface usaseg
	/// </summary>
	public abstract class AbstractRegularPolygen : IRegularPolygen
	{
		public int NumberOfSide { get; set; }
		public int SideLength { get; set; }
		public AbstractRegularPolygen()
		{
		}
		public AbstractRegularPolygen(int _sideLength, int _numberOfSide)
		{
			NumberOfSide = _numberOfSide;
			SideLength = _sideLength;
		}
		public double GetPerimeter()
		{
			return NumberOfSide * SideLength;
		}
		public abstract double GetArea();

	}
}
