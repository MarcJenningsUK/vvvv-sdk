#region usings
using System;
using System.Collections.Generic;
using System.ComponentModel.Composition;

using VVVV.PluginInterfaces.V1;
using VVVV.PluginInterfaces.V2;
using VVVV.Utils.VColor;
using VVVV.Utils.VMath;

using VVVV.Core;
using VVVV.Core.Logging;
using VVVV.Hosting.Factories;
#endregion usings

namespace VVVV.Nodes
{
	#region PluginInfo
	[PluginInfo(Name = "NodeCollector", Category = "VVVV", 
	            Help = "Scans the specified directories for nodes and makes them available. Job directories are expected to have nodes sorted in subdirectories by type (effects, plugins, modules...)", 
	            Tags = "", AutoEvaluate = true)]
	#endregion PluginInfo
	public class NodeCollector : IPluginEvaluate
	{
		#region fields & pins
		[Input("Job Directories", StringType = StringType.Directory, DefaultString = ".")]
		ISpread<string> FJobDirs;		
		List<string> FLastJobs = new List<string>();

		[Input("Unsorted Directories", StringType = StringType.Directory)]
		ISpread<string> FUnsortedDirs;
		
		[Import()]
		NodeCollection NodeCollection;
		
		[Import()]
		ILogger Flogger;
		#endregion fields & pins

		List<string> FDirs;
			
		//called when data for any output pin is requested
		public void Evaluate(int SpreadMax)
		{
			foreach (var p in FLastJobs)
				NodeCollection.RemoveJob(p);				

			FLastJobs.Clear();
			
			foreach (var p in FJobDirs)
			{
				NodeCollection.AddJob(p);
				FLastJobs.Add(p);
			}

			NodeCollection.Collect();
		}
	}	
}