namespace DPinCsharp
{
	#region concreteclass
	public interface Shape
	{
		void draw();
	}
	public class Circle : Shape
	{
		public void draw()
		{
			System.Console.WriteLine("Draw cicle ");
		}
	}
	public class Triangle : Shape
	{
		public void draw()
		{
			System.Console.WriteLine("Draw Triangle ");
		}
	}
	public class Square : Shape
	{
		public void draw()
		{
			System.Console.WriteLine("Draw Square ");
		}
	}
	#endregion

	public enum EShape { CIRCLE, TRIANGLE, SQUARE }
	public class ShapeFactory
	{
		public static Shape GetShape(EShape eShape)
		{
			Shape shape = null;
			switch (eShape)
			{
				case EShape.CIRCLE:
					shape = new Circle();
					break;
				case EShape.TRIANGLE:
					shape = new Triangle();
					break;
				case EShape.SQUARE:
					shape = new Square();
					break;
				default:
					break;
			}
			return shape;
		}
	}
	public class DemoFactory
	{
		public static void Demo()
		{
			Shape shape = null;
			shape = ShapeFactory.GetShape(EShape.CIRCLE);
			shape.draw();
			shape = ShapeFactory.GetShape(EShape.SQUARE);
			shape.draw();
			shape = ShapeFactory.GetShape(EShape.TRIANGLE);
			shape.draw();

		}
	}

}
