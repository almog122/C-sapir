using NUnit.Framework;
using System;

namespace Targil_12_TestCase
{
	[TestFixture]
	public class Tests
	{

		[SetUp]
		public void Setup()
		{	
		}
		
		[Test]
		public void Character()
		{
			Assert.That(SentenceUtils.ToTitleCase("a"), Is.EqualTo("A"), "expected: A , result : " + SentenceUtils.ToTitleCase("a"));
			Assert.That(SentenceUtils.ToTitleCase("K"), Is.EqualTo("K"), "expected: K , result : " + SentenceUtils.ToTitleCase("K"));
		}

		[Test]
		public void Word()
		{
			Assert.That(SentenceUtils.ToTitleCase("Work"), Is.EqualTo("Work"), "expected: Work , result : " + SentenceUtils.ToTitleCase("Work"));
			Assert.That(SentenceUtils.ToTitleCase("scReEn"), Is.EqualTo("Screen"), "expected: Screen , result : " + SentenceUtils.ToTitleCase("scReEn"));
			Assert.That(SentenceUtils.ToTitleCase("PoTaTO"), Is.EqualTo("Potato"), "expected: Potato , result : " + SentenceUtils.ToTitleCase("PoTaTO"));
			Assert.That(SentenceUtils.ToTitleCase("KFC"), Is.EqualTo("Kfc"), "expected: Kfc , result : " + SentenceUtils.ToTitleCase("KFC"));
		}

		[Test]
		public void Sentence()
		{
			Assert.That(SentenceUtils.ToTitleCase("This is SO  MUCH  FUN!"), Is.EqualTo("This Is So  Much  Fun!"), "expected : This Is So  Much  Fun! , result : " + SentenceUtils.ToTitleCase("This is SO MUCH  FUN!"));
		}

		[Test]
		public void MultipleWhitespace()
		{
			Assert.That(SentenceUtils.ToTitleCase("    "), Is.EqualTo("    "), "expected:      , result : " + SentenceUtils.ToTitleCase("    "));
		}

	}
}



