#include "Music.h"

Music::Music(const string& name, const string& extension, size_t size_in_mb, const string& singer, const string& mName, size_t year)
	: File(name, ((extension == ".mp3" || extension == ".flac") ? extension : ".mp3"), size_in_mb)
	, m_singer(singer)
	, m_name(mName)
	, m_year(year)
{}