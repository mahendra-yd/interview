using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.WindowsAzure;
using Microsoft.WindowsAzure.Diagnostics;
using Microsoft.WindowsAzure.ServiceRuntime;
using System.Net;
using System.Threading;
using Microsoft.ServiceBus;
using Microsoft.ServiceBus.Messaging;
using Microsoft.WindowsAzure;
namespace SampleRestServiceWeb
{
	public class WebRole : RoleEntryPoint
	{
		// The name of your queue
		const string QueueName = "ProcessingQueue";

		// QueueClient is thread-safe. Recommended that you cache 
		// rather than recreating it on every request
		QueueClient Client;
		public override bool OnStart()
		{
			// For information on handling configuration changes
			// see the MSDN topic at https://go.microsoft.com/fwlink/?LinkId=166357.

			return base.OnStart();
		}
	}
}
