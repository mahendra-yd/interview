using System;

namespace Polygen.Library
{
	public class ConcreteRegularClass : IRegularPolygen
	{
		public int NumberOfSide { get; set; }
		public int SideLength { get; set; }
		public ConcreteRegularClass()
		{
		}
		public ConcreteRegularClass(int _sideLength, int _numberOfSide)
		{
			NumberOfSide = _numberOfSide;
			SideLength = _sideLength;
		}
		public double GetPerimeter()
		{
			return NumberOfSide * SideLength;
		}
		public virtual double GetArea()
		{
			throw new NotImplementedException();
		}
	}
}
