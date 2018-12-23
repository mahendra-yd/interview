namespace Polygen.Library
{
	public interface IRegularPolygen
	{
		int NumberOfSide { get; set; }
		int SideLength { get; set; }
		double GetPerimeter();
		double GetArea();

	}
}
