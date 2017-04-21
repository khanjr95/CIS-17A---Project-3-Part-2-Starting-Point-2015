#include "Folder.h"
#include <iostream>

Folder::Folder(std::string name) : _name(name)
{
}

Folder::Folder(){}

Folder::~Folder()
{
}

std::vector<std::string> Folder::ListFiles()
{
	std::vector<std::string> list;
	for (auto file : _files) {
		list.push_back(file->getName());
	}
	return list;
}

std::string Folder::ListContents()
{
	std::string output = "\n";
	for (auto folder : _folders) {
		output += "\\" + folder->getName() + "\n";
	}
	for (auto file : _files) {
		output += file->getName() + "\n";		
	}
	return output;
}

void Folder::AddFile(std::shared_ptr<File> newFile)
{
	_files.push_back(newFile);
}

void Folder::AddFolder(std::shared_ptr<Folder> newFolder)
{
	_folders.push_back(newFolder);
}

std::shared_ptr<Folder> Folder::FindFolder(std::string name)
{
	for(auto folder : _folders)
	{
		if (folder->getName() == name) {
			return folder;
		}
	}
	return nullptr;
}

std::shared_ptr<File> Folder::Search(std::string name)
{
	{
		for (auto file : _files)
		{
			if (file->getName() == name)
			{
				std::cout << "File Found: " << name << "\n";
				std::cout<< "Located in Folder: " << getName() << "\n";
				FindFolder(getName());
				return file;
			}
			
		}

		for (auto folder : _folders)
		{
			auto file = folder->Search(name);
			if (file != nullptr)
			{
				return file;
			}
			else
			{
				std::cout << "File not found or does not exist! \n";
			}
		}
		return nullptr;
	}

	//loop/iterate this folder's files
	/*for (auto file : _files)
	{
		if (file->getName() == name)
		{
			return file;
		}
	}*/
	//if you find a file with the passed in name, return it


	//loop/iterate this folder's folders
	//for (auto folder : _folders)
	//{
	//	auto file = folder->Search(name);
	//	if (file != nullptr)
	//	{
	//		return file;
	//	}
	//}
	//Search(each folder in the loop)
	//Otherwise return nullptr
}