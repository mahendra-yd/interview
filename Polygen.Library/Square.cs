namespace Polygen.Library
{
	public class Square : ConcreteRegularClass
	{
		public Square(int _sideLength) : base(4, _sideLength)
		{
		}
		public override double GetArea()
		{
			return base.NumberOfSide * base.SideLength;
		}

	}
}
