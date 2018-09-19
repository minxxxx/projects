using System;

namespace ComputerV1
{
    class InvalidEquationException : Exception
    {
        public InvalidEquationException(string message) : base(message) { }
    }
}
