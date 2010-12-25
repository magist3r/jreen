/****************************************************************************
 *  bookmark.h
 *
 *  Copyright (c) 2010 by Sidorov Aleksey <sauron@citadelspb.com>
 *
 ***************************************************************************
 *                                                                         *
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************
*****************************************************************************/

#ifndef BOOKMARK_H
#define BOOKMARK_H
#include "stanzaextension.h"
#include "jid.h"

namespace jreen {

//XEP-0048
//http://xmpp.org/extensions/xep-0048.html
class BookmarkPrivate;
/*! For ease-of-use in a Jabber client, it is desirable to have a way to store shortcuts
* to various services and resources (such as conference rooms and web pages) as "bookmarks"
* that can be displayed in the user's client.
* Several Jabber clients have already agreed on and implemented a method to provide this service;
* that informal agreement is documented and expanded upon in this document
*/
class JREEN_EXPORT Bookmark : public StanzaExtension
{
	Q_DECLARE_PRIVATE(Bookmark)
	J_EXTENSION(jreen::Bookmark,"") //dummy
public:
	/*! Default constructor \param jid - The JabberID of the chat room
	  * \param name - A friendly name for the bookmark(optional)
	  * \param nick - The user's preferred roomnick for the chatroom(optional).
	  */
	Bookmark(const JID &jid,const QString &name = QString(), const QString &nick = QString());
	/*! set friendly name of bookmark
	  */
	~Bookmark();
	void setName(const QString &name);
	/*! set the user's preferred roomnick for the chatroom
	  */
	void setNick(const QString &nick);
	/*! set an unencrypted string for the password needed to enter a password-protected room.
	 *  \note For security reasons, use of this element is NOT RECOMMENDED.
	 */
	void setPassword(const QString &password);
	/*! set autojoin attribute
	  */
	void setAutojoin(bool set);
	/*! returns friendly name of bookmark
	  */
	QString name() const;
	/*! returns friendly name of bookmark
	  */
	QString nick() const;
	/*! returns the user's preferred roomnick for the chatroom
	  */
	QString password() const;
	/*! returns JabberID of the chat room.
	  */
	JID jid() const;
	/*! returns autojoin attribute
	  */
	bool autojoin() const;
private:
	QScopedPointer<BookmarkPrivate> d_ptr;
};

} // namespace jreen

#endif // BOOKMARK_H