namespace DPinCsharp.AbstractFactory
{

	#region concreteclass
	public interface Color
	{
		void Fill();
	}
	public class Red : Color
	{
		public void Fill()
		{
			System.Console.WriteLine("Fill RED ");
		}
	}
	public class Green : Color
	{
		public void Fill()
		{
			System.Console.WriteLine("Fill Green ");
		}
	}
	public class Blue : Color
	{
		public void Fill()
		{
			System.Console.WriteLine("Fill Blue ");
		}
	}

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
	public enum EColor { RED, GREEN, BLUE }
	public interface AbstractFactory
	{
		Color GetColor(EColor e);
		Shape GetShape(EShape e);
	}
	public class ColorFactory : AbstractFactory
	{
		public Color GetColor(EColor eColor)
		{
			Color color = null;
			switch (eColor)
			{
				case EColor.RED:
					color = new Red();
					break;
				case EColor.GREEN:
					color = new Green();
					break;
				case EColor.BLUE:
					color = new Blue();
					break;
				default:
					break;
			}
			return color;
		}


		public Shape GetShape(EShape e)
		{
			throw new System.NotImplementedException();
		}
	}
	public class ShapeFactory : AbstractFactory
	{
		public Shape GetShape(EShape eShape)
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

		public Color GetColor(EColor e)
		{
			throw new System.NotImplementedException();
		}

	}

	public class FactoryProducer
	{
		public static AbstractFactory getFactory(string type)
		{

			switch (type)
			{
				case "shape": return new ShapeFactory();
				case "color": return new ColorFactory();
				default:
					return null;

			}
		}
	}
	public class AbstractFactoryDemo
	{

		public static void demo()
		{
			AbstractFactory shapefactory = FactoryProducer.getFactory("shape");
			Shape shape = shapefactory.GetShape(EShape.CIRCLE);
			shape.draw();
			AbstractFactory colorfactory = FactoryProducer.getFactory("color");
			Color color = colorfactory.GetColor(EColor.GREEN);
			color.Fill();
		}
	}
}
