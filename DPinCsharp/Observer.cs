using System.Collections.Generic;

namespace DPinCsharp
{
   public class DemoObserver
    {
        public static void Demo()
        {
            Ipublisher ipublisher = new StockPublisher();
            ipublisher.register(new FirstSubscriber() { Name="first"});
            ipublisher.register(new SecondSubscriber() { Name= "second"});
            ipublisher.notify();
        }
    }
    public interface Isubscriber
    {
        string Name { get; set; }
        void update(string info);
    }

    public class FirstSubscriber : Isubscriber
    {
        public string Name { get ; set; }

        public void update(string info)
        {
            System.Console.WriteLine("Got Update "+ info);
        }
    }

    public class SecondSubscriber : Isubscriber
    {
        public string Name { get; set; }

        public void update(string info)
        {
            System.Console.WriteLine("Got Update " + info);
        }
    }

    public interface Ipublisher
    {
        void register(Isubscriber n);
        void unregister(Isubscriber n);
        void notify();
    }
    public class StockPublisher : Ipublisher
    {
        List<Isubscriber> subscribers = new List<Isubscriber>();
        public void notify()
        {
            foreach (var item in subscribers)
            {
                item.update("Hello " + item.Name);
            }
        }

        public void register(Isubscriber isubscriber)
        {
            subscribers.Add(isubscriber);
        }

        public void unregister(Isubscriber isubscriber)
        {
            subscribers.Remove(isubscriber);

        }
    }

}
