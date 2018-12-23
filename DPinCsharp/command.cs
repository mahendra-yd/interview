using System;

namespace DPinCsharp
{
    /*
     *  Make electronic Interface
     *  Make Command Interface
     *  Make electronic device
     *  Make command and assign device
     *  Make Button and assign a command
     *  assign buttons in a remote and include method press
     */
    public class DemoCommand
    {
        public static void Demo()
        {
            IElectronicDevice electronicDevice = Remote.GetTVRemote();
            Button TVonButton = new Button(new On(electronicDevice));
            Button TVoffButton = new Button(new Off(electronicDevice));
            TVonButton.press();
            TVoffButton.press();

            //.........................
            electronicDevice = Remote.GetRadioRemote();
            Button RadioOnButton = new Button(new On(electronicDevice));
            Button RadioOffButton = new Button(new Off(electronicDevice));
            RadioOnButton.press();
            RadioOffButton.press();


        }
    }
    public interface Icommand
    {
        void excute();
        void undo();
    }

    public class Remote
    {
        public static IElectronicDevice GetTVRemote()
        {
            return new TV();
        }
        public static IElectronicDevice GetRadioRemote()
        {
            return new Radio();
        }
    }

    public class Button
    {
        Icommand icommand;

        public Button(Icommand icommand)
        {
            this.icommand = icommand;
        }
        public void press()
        {
            icommand.excute();
        }
    }
    public class VolumeDown : Icommand
    {
        IElectronicDevice electronicDevice;
        public VolumeDown(IElectronicDevice electronicDevice)
        {
            this.electronicDevice = electronicDevice;
        }
        public void excute()
        {
            electronicDevice.volumeUP();
        }

        public void undo()
        {
            electronicDevice.volumeDown();
        }
    }
    public class VolumeUp : Icommand
    {
        IElectronicDevice electronicDevice;
        public VolumeUp(IElectronicDevice electronicDevice)
        {
            this.electronicDevice = electronicDevice;
        }
        public void excute()
        {
            electronicDevice.volumeUP();
        }

        public void undo()
        {
            electronicDevice.volumeDown();
        }
    }

    public class Off : Icommand
    {
        IElectronicDevice electronicDevice;
        public Off(IElectronicDevice electronicDevice)
        {
            this.electronicDevice = electronicDevice;
        }
        public void excute()
        {
            electronicDevice.off();
        }

        public void undo()
        {
            electronicDevice.on();
        }
    }
    public class On : Icommand
    {
        IElectronicDevice electronicDevice;
        public On(IElectronicDevice electronicDevice)
        {
            this.electronicDevice = electronicDevice;
        }
        public void excute()
        {
            electronicDevice.on();
        }

        public void undo()
        {
            electronicDevice.off();
        }
    }
    public interface IElectronicDevice
    {
        void on();
        void off();
        void volumeUP();
        void volumeDown();
    }
    public class TV : IElectronicDevice
    {
        public void off()
        {
            Console.WriteLine("TV OFF");
        }

        public void on()
        {
            Console.WriteLine("TV ON");
        }

        public void volumeDown()
        {
            Console.WriteLine("TV Volume UP");
        }

        public void volumeUP()
        {
            Console.WriteLine("TV Volume Down");
        }
    }
    public class Radio : IElectronicDevice
    {
        public void off()
        {
            Console.WriteLine("Radio OFF");
        }

        public void on()
        {
            Console.WriteLine("Radio ON");
        }

        public void volumeDown()
        {
            Console.WriteLine("Radio Volume UP");
        }

        public void volumeUP()
        {
            Console.WriteLine("Radio Volume Down");
        }
    }

}
