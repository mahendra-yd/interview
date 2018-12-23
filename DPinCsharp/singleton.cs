using System;

namespace DPinCsharp
{
	public class DemoSingleton
	{
		public static void Demo()
		{
			Singleton.GetInstance.PrintMessage("Hello Bro");

			Singleton.GetInstance.PrintMessage("Hello Bro");
			Singleton.GetInstance.PrintMessage("Hello Bro");
		}
	}
	sealed public class Singleton
	{
		private Singleton() { }
		private static Singleton singletonInstance = null;
		public static Singleton GetInstance
		{
			get
			{

				if (singletonInstance == null)
				{
					lock (new object())
					{
						if (singletonInstance == null)
						{
							singletonInstance = new Singleton();
						}
					}

				}
				return singletonInstance;
			}

		}
		public void PrintMessage(string message)
		{
			Console.WriteLine(message);
		}
	}
	public class SingletonEarly
	{
		private SingletonEarly() { }
		private static SingletonEarly singletonInstance = new SingletonEarly();
		public static SingletonEarly getSingleInstance
		{
			get
			{
				return singletonInstance;
			}
		}


	}
	public sealed class SingletonLazy
	{
		private static readonly Lazy<SingletonLazy> lazy =
	   new Lazy<SingletonLazy>(() => new SingletonLazy());

		public static SingletonLazy Instance { get { return lazy.Value; } }

		private SingletonLazy()
		{
		}
	}
}