#ifndef FEDHeader_H
#define FEDHeader_H

/** \class FEDHeader
 *  TEMPORARY helper class to interpret/create FED header words.
 *  FIXME: will be replaced by the xdaq implementation.
 *
 *  $Date: 2005/09/30 08:13:36 $
 *  $Revision: 1.1 $
 *  \author N. Amapane - CERN
 */

struct fedh_struct;

class FEDHeader {
public:
  /// Constructor
  FEDHeader(const unsigned char* header);

  /// Destructor
  ~FEDHeader();

  /// Event Trigger type identifier
  int triggerType();

  /// Level-1 event number generated by the TTC system
  int lvl1ID();

  /// The bunch crossing number
  int bxID();

  /// Identifier of the FED
  int sourceID();

  /// Version identifier of the FED data format
  int version();

  /// 0 -> the current header word is the last one.
  /// 1-> other header words can follow 
  /// (always 1 for ECAL)
  bool moreHeaders();

  // Check that the header is OK
  bool check();

  /// Set all fields in the header
  static void set(unsigned char* header,
		  int evt_ty,
		  int lvl1_ID,
		  int bx_ID,  
		  int source_ID,
		  int version=0,
		  bool H=false);

private:
  const fedh_struct* theHeader;
};
#endif

