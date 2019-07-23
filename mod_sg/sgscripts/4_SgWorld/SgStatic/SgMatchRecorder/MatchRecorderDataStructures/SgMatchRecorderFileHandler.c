// FileHandle wrapper, for cases when FileHandle need to be in array or map, which is not supported, since it is only defined as int[] .. programmers solution.
class SgMatchRecorderFileHandler
{
	FileHandle m_fileHandle;
	
	void SgMatchRecorderFileHandler(string path, FileMode fileMode)
	{
		m_fileHandle = OpenFile(path, fileMode);
	}
}