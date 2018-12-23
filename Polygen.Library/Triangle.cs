using System;

namespace Polygen.Library
{
	public class Triangle : AbstractRegularPolygen
	{
		public Triangle(int _lenght) : base(3, _lenght)
		{

		}

		public override double GetArea()
		{
			return this.SideLength * SideLength * Math.Sqrt(3) / 4;
		}
	}
}
