﻿
using System;
using System.Collections.Generic;

/// <summary>
/// Utils to work with Linq.
/// </summary>
namespace VVVV.Utils.Linq
{
	public static class LinqExtensions
	{
		public static IEnumerable<T> AsDepthFirstEnumerable<T>(this T parent) where T: IEnumerable<T>
		{
			yield return parent;
			foreach (var subTree in parent)
			{
				foreach (var child in subTree.AsDepthFirstEnumerable())
				{
					yield return child;
				}
			}
		}
	}
}
