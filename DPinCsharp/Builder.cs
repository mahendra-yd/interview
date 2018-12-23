using System;

namespace DPinCsharp
{

    namespace PizzaName
    {
        public static class DemoBuilder
        {
            public static void Demo()
            {
                IPizaaBuilder pizaaBuilder = new Pizza();
                PizzaCreator pizzaCreator = new PizzaCreator(pizaaBuilder);
                pizzaCreator.withCheese(Cheese.Mexican).withCrsut(Crust.Thick).withSize(Size.Medium).withTopping(Topping.Mushroom);
                Console.WriteLine( pizzaCreator.GetPizza().Price);
            }
        }
        public static class Extension
        {
            public static float GetPrice(this Topping topping)
            {
                switch (topping)
                {
                    case Topping.PEPPRONY:
                        return 10;
                    case Topping.Chicken:
                        return 20;
                    case Topping.Mushroom:
                        return 30;
                    default:
                        return 0;
                }
            }
            public static float GetPrice(this Size size)
            {
                switch (size)
                {
                    case Size.Small:
                        return 10;
                    case Size.Medium:
                        return 20;
                    case Size.Family:
                        return 30;
                    default:
                        return 0;
                }
            }
            public static float GetPrice(this Crust crust)
            {
                switch (crust)
                {
                    case Crust.Thin:
                        return 20;
                    case Crust.Thick:
                        return 30;
                    default:
                        return 0;
                }
            }
            public static float GetPrice(this Cheese cheese)
            {
                switch (cheese)
                {
                    case Cheese.American:
                        return 10;
                    case Cheese.Mexican:
                        return 20;
                    default:
                        return 0;
                }
            }
        }
        public enum Cheese { American, Mexican }
        public enum Crust { Thin, Thick }
        public enum Size { Small, Medium, Family }
        public enum Topping { PEPPRONY, Chicken, Mushroom }

        interface IPizaaBuilder
        {
            void addCrust(Crust crust);
            void addTopping(Topping topping);
            void addSize(Size size);
            void addCheese(Cheese cheese);
            Pizza build();
            float price();

        }

        public class Pizza : IPizaaBuilder
        {
            private float price;
            private Cheese _cheese;
            private Crust _crust;
            private Size _size;
            private Topping _topping;

            public Topping topping
            {
                get { return _topping; }
                set { _topping = value; }
            }


            public Size size
            {
                get { return _size; }
                set { _size = value; }
            }


            public Crust crust
            {
                get { return _crust; }
                set { _crust = value; }
            }

            public Cheese cheese
            {
                get { return _cheese; }
                set { _cheese = value; }
            }

            public float Price
            {
                get { return price; }
                set { price = value; }
            }

            public void addCheese(Cheese cheese)
            {
                this.cheese = cheese;

                this.addPrice(cheese.GetPrice());

            }

            public void addCrust(Crust crust)
            {
                this.crust = crust;
                this.addPrice(crust.GetPrice());
            }

            public void addSize(Size size)
            {
                this.size = size;
                this.addPrice(size.GetPrice());
            }

            public void addTopping(Topping topping)
            {
                this.topping = topping;
                this.addPrice(topping.GetPrice());
            }

            public Pizza build()
            {
                Console.WriteLine("pizza cokked");
                return this;
            }

            void addPrice(float price)
            {
                this.price += price;
            }

            float IPizaaBuilder.price()
            {
                throw new NotImplementedException();
            }
        }

        class PizzaCreator
        {
            IPizaaBuilder pizaaBuilder;
            public PizzaCreator(IPizaaBuilder pizaaBuilder)
            {
                this.pizaaBuilder = pizaaBuilder;

            }
            public PizzaCreator withTopping(Topping topping)
            {
                pizaaBuilder.addTopping(topping);
                return this;
            }

            public PizzaCreator withCrsut(Crust crust)
            {
                pizaaBuilder.addCrust(crust);
                return this;
            }

            public PizzaCreator withSize(Size size)
            {
                pizaaBuilder.addSize(size);
                return this;
            }

            public PizzaCreator withCheese(Cheese cheese)
            {
                pizaaBuilder.addCheese(cheese);
                return this;
            }
            public Pizza GetPizza()
            {
                return pizaaBuilder.build();
            }
            public float GetPrice()
            {
                return pizaaBuilder.price();
            }
        }
    }
    namespace ComputerName
    {

        public class ComputerNamedemo
        {
            public static void demo()
            {
                Computer computer = new Computer.ComputerBuilder(4, 500).SetBluetoothEnabled(true).SetGraphicEnabled(false).Build();
                computer.DisplayComputer();
            }
        }

        public class Computer

        {
            public int Ram { get; }
            public int Disk { get; }
            public bool isGraphicEnabled { get; }
            public bool isBlutoothEnabled { get; }

            public void DisplayComputer()
            {
                Console.WriteLine("Ram = {0} Disck ={1} Graphic {2} Bluetooth {3}", Ram, Disk, isGraphicEnabled, isBlutoothEnabled);
            }
            public Computer(ComputerBuilder computerBuilder)
            {
                this.Ram = computerBuilder.Ram;
                this.Disk = computerBuilder.Disk;
                this.isGraphicEnabled = computerBuilder.isGraphicEnabled;
                this.isBlutoothEnabled = computerBuilder.isBlueToothEnabled;
            }

            public class ComputerBuilder
            {
                public int Ram;
                public int Disk;
                public bool isGraphicEnabled;
                public bool isBlueToothEnabled;

                public ComputerBuilder(int newRam, int newDisk)
                {
                    Ram = newRam;
                    Disk = newDisk;
                }

                public ComputerBuilder SetGraphicEnabled(bool value)
                {
                    isGraphicEnabled = value;
                    return this;
                }
                public ComputerBuilder SetBluetoothEnabled(bool value)
                {
                    isBlueToothEnabled = value;
                    return this;
                }

                public Computer Build()
                {
                    return new Computer(this);
                }


            }

        }

    }
}
