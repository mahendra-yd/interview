using System;

namespace DPinCsharp
{
    public class DemochainOfResponsibility
    {
        public static void Demo()
        {
            chainOfResponsibility ch = Init();
            Number number = new Number() { a = 5, b = 6, op = "*" };
            ch.excecute(number);
        }

        private static chainOfResponsibility Init()
        {
            chainOfResponsibility chainOfResponsibilitySum = new Add();
            chainOfResponsibility chainOfResponsibilitySub = new Sub();
            chainOfResponsibility chainOfResponsibilityMul = new Mul();
            chainOfResponsibility chainOfResponsibilityDiv = new Division();
            chainOfResponsibilitySum.setNextChain(chainOfResponsibilitySub);
            chainOfResponsibilitySub.setNextChain(chainOfResponsibilityMul);
            chainOfResponsibilityMul.setNextChain(chainOfResponsibilityDiv);
            return chainOfResponsibilitySum;
        }
    }
    public interface chainOfResponsibility
    {
        void setNextChain(chainOfResponsibility chainOfResponsibility);
        void excecute(Number number);
    }
    public class Number
    {
        public int a { get; set; }
        public int b { get; set; }
        public string op { get; set; }
    }

    public class Add : chainOfResponsibility
    {
        chainOfResponsibility nextChain = null;
        public void excecute(Number number)
        {
            if (number.op == "+")
            {
                Console.WriteLine("Sum =" + number.a + number.b);
            }
            else
            {
                if (null != nextChain)
                {
                    nextChain.excecute(number);
                }
                else
                {
                    Console.WriteLine("Operation not supported");
                }

            }
        }

        public void setNextChain(chainOfResponsibility chainOfResponsibility)
        {
            if (null == nextChain)
            {
                nextChain = chainOfResponsibility;
            }
            //nextChain?? (nextChain= chainOfResponsibility);
        }
    }


    public class Sub : chainOfResponsibility
    {
        chainOfResponsibility nextChain = null;
        public void excecute(Number number)
        {
            if (number.op == "-")
            {
                Console.WriteLine("Sub =" + (number.a - number.b));
            }
            else
            {
                if (null != nextChain)
                {
                    nextChain.excecute(number);
                }
                else
                {
                    Console.WriteLine("Operation not supported");
                }

            }
        }

        public void setNextChain(chainOfResponsibility chainOfResponsibility)
        {
            if (null == nextChain)
            {
                nextChain = chainOfResponsibility;
            }
            //nextChain?? (nextChain= chainOfResponsibility);
        }
    }


    public class Mul : chainOfResponsibility
    {
        chainOfResponsibility nextChain = null;
        public void excecute(Number number)
        {
            if (number.op == "*")
            {
                Console.WriteLine("Multiplication =" + number.a * number.b);
            }
            else
            {
                if (null != nextChain)
                {
                    nextChain.excecute(number);
                }
                else
                {
                    Console.WriteLine("Operation not supported");
                }

            }
        }

        public void setNextChain(chainOfResponsibility chainOfResponsibility)
        {
            if (null == nextChain)
            {
                nextChain = chainOfResponsibility;
            }
            //nextChain?? (nextChain= chainOfResponsibility);
        }
    }


    public class Division : chainOfResponsibility
    {
        chainOfResponsibility nextChain = null;
        public void excecute(Number number)
        {
            if (number.op == "/")
            {
                Console.WriteLine("Division =" + number.a / number.b);
            }
            else
            {
                if (null != nextChain)
                {
                    nextChain.excecute(number);
                }
                else
                {
                    Console.WriteLine("Operation not supported");
                }

            }
        }

        public void setNextChain(chainOfResponsibility chainOfResponsibility)
        {
            if (null == nextChain)
            {
                nextChain = chainOfResponsibility;
            }
            //nextChain?? (nextChain= chainOfResponsibility);
        }
    }

}
