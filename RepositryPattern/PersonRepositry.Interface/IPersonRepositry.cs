using System.Collections.Generic;
namespace PersonRepositry.Interface
{
	public interface IPersonRepositry
	{
		IEnumerable<Person> GetPeople();

		Person GetPerson(string LName);
		void AddPerson(Person newPerson);
		void UpdatePerson(string LName, Person updatedPerson);
		void DeletePerson(string LName);
		void DeletePeoples(IEnumerable<Person> removeList);
	}
}
