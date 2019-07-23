class SgJsonStaticCamera
{
  vector m_Position;
  vector m_Orientation;
  
  void SetPosition( vector position )
  {
    m_Position = position;
  }
  void SetOrientation( vector orientation )
  {
    m_Orientation = orientation;
  }
  
  vector GetPosition()
  {
    return m_Position;
  }
  vector GetOrientation()
  {
    return m_Orientation;
  }
}
