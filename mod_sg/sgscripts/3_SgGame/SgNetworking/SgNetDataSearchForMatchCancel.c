// DESIGN_ID: 0001

/*
	- "Pseudo Abstract" class for canceling a game search 
	- NOTE: Apparently there is not a server response yet
*/
class SgNetDataSearchForMatchCancel {}

/*
	- SG network request data class for server to stop looking for a match game
*/
class SgNetDataSearchForMatchCancelRequest extends SgNetDataSearchForMatchCancel
{
}

/*
	- SG network response data class for server to stop looking for a match game
*/
class SgNetDataSearchForMatchCancelResponse extends SgNetDataSearchForMatchCancel
{
}


