#!/usr/bin/python
import MySQLdb
  

#written by rein of tmw/evol

#credit to bruder torgen of phpbb.com. for his black magic sql statements. 
#https://www.phpbb.com/community/viewtopic.php?f=65&t=1917165
#hope it runs smooth as it does for me



#   this script has little to no error checking
#        it         is         uggly! 
# presented as is , working in test environment,
# ready for inspction and testing in production environment.

#note.. did not fully implement privmsgs
#but left code for it in included file



#-----------preperation-------------------------------------------------------
# backup both forum dbs        (in the event of failure start fresh . do not attempt salvage or a second execution  on damaged db)
#
# db1 source 
# db2 target
# will yeild a forum with the settings of db2 with combined content of both
#
# from db1 backup tables:
# phpbb_users,phpbb_topics,phpbb_forums,phpbb_posts,phpbb_privmsgs,phpbb_privmsgs_to,phpbb_attachments,phpbb_poll_votes,phpbb_poll_options
#
# edit the backup tables
# find and "replace all" add a suffix of _2  (eg. phpbb_users_2,phpbb_topics_2 etc ) to the table names
# import modified tables into db2
#
# db2 is now the working database for the merge 



#---------operation------------------------------------
#fill in the nessicary db connection info then execute with python.

#this will take some luck 

#after sucesfull execution . 
#caches will need to be clered
#resynch and reset everything (post count users online cache active sessions etc)
#and permissions will need to be setup or the forums will be invisable to admin and user alike









#ignore the example values they are from bruder torgens forum entries .used as refference
global maxuser   #example 133
global maxforum  #example 34
global maxright  #example 68
global maxattach
global maxtopic  #example 424
global maxpost  #example 9959
global maxmsg  #example 406

print"rein: hello tmw/evol"
# Open database connection  -  user pass database
print "connecting"
db = MySQLdb.connect("localhost","phpBB","pass500","phpBB" )
cursor = db.cursor()

#----------------users--------------------------------------------------------------------------------------

#add duplicate user colum to users2
cursor.execute("alter table phpbb_users_2 add user_id_old mediumint(8) ")

#get usercount`
cursor.execute("SELECT max( user_id ) FROM phpbb_users;")
data = cursor.fetchone()
maxuser=data
print "maxuser : %s " % maxuser

# remove the auto increment attribute and primary key index
cursor.execute("ALTER TABLE phpbb_users_2 CHANGE `user_id` `user_id` MEDIUMINT( 8 ) UNSIGNED NOT NULL;")
cursor.execute("alter table phpbb_users_2 drop primary key;")

# update users in user2 with new incremented ids
print "updating ids"
cursor.execute("update phpbb_users_2 set user_id = user_id + %s;" % maxuser)
cursor.execute("update phpbb_posts_2 set poster_id = poster_id +  %s;" % maxuser)

##update related tables
cursor.execute("update phpbb_topics_2 set topic_poster = topic_poster + %s;" % maxuser)
cursor.execute("update phpbb_topics_2 set topic_last_poster_id = topic_last_poster_id +%s;" % maxuser)
cursor.execute("update phpbb_forums_2 set forum_last_poster_id = forum_last_poster_id + %s;" % maxuser)
cursor.execute("update phpbb_privmsgs_2 set author_id = author_id + %s;" % maxuser)
cursor.execute("update phpbb_privmsgs_to_2 set user_id = user_id + %s;" % maxuser)
cursor.execute("update phpbb_privmsgs_to_2 set author_id = author_id+ %s ;" % maxuser)
cursor.execute("update phpbb_attachments_2 set poster_id = poster_id + %s;" % maxuser)
cursor.execute("update phpbb_poll_votes_2 set vote_user_id = vote_user_id + %s;" % maxuser)


#identify duplicates
cursor.execute("UPDATE phpbb_users_2, phpbb_users SET phpbb_users_2.user_id_old = phpbb_users_2.user_id, phpbb_users_2.user_id = phpbb_users.user_id WHERE phpbb_users_2.username_clean LIKE phpbb_users.username_clean;")

cursor.execute("update phpbb_posts_2, phpbb_users_2 set phpbb_posts_2.poster_id = phpbb_users_2.user_id where phpbb_posts_2.poster_id = phpbb_users_2.user_id_old;")
cursor.execute("update phpbb_forums_2, phpbb_users_2 set phpbb_forums_2.forum_last_poster_id = phpbb_users_2.user_id where phpbb_forums_2.forum_last_poster_id = phpbb_users_2.user_id_old;")
cursor.execute("update phpbb_topics_2, phpbb_users_2 set phpbb_topics_2.topic_poster = phpbb_users_2.user_id where phpbb_topics_2.topic_poster = phpbb_users_2.user_id_old;")
cursor.execute("update phpbb_topics_2, phpbb_users_2 set phpbb_topics_2.topic_last_poster_id = phpbb_users_2.user_id where phpbb_topics_2.topic_last_poster_id = phpbb_users_2.user_id_old;")
cursor.execute("update phpbb_privmsgs_2, phpbb_users_2 set phpbb_privmsgs_2.author_id = phpbb_users_2.user_id where phpbb_privmsgs_2.author_id = phpbb_users_2.user_id_old;")
cursor.execute("update phpbb_privmsgs_to_2, phpbb_users_2 set phpbb_privmsgs_to_2.author_id = phpbb_users_2.user_id where phpbb_privmsgs_to_2.author_id = phpbb_users_2.user_id_old;")
cursor.execute("update phpbb_privmsgs_to_2, phpbb_users_2 set phpbb_privmsgs_to_2.user_id = phpbb_users_2.user_id where phpbb_privmsgs_to_2.user_id = phpbb_users_2.user_id_old;")

#deactivate added users . optionallllll and annoying dont enable lol
#cursor.execute("update phpbb_users_2 set user_type = 1 where user_id_old is null;")

#merge users
print "merging users!"
cursor.execute("INSERT INTO phpbb_users (user_id, user_type, group_id, user_permissions, user_perm_from, user_ip, user_regdate, username, username_clean, user_password, user_passchg, user_pass_convert, user_email, user_email_hash, user_birthday, user_lastvisit, user_lastmark, user_lastpost_time, user_lastpage, user_last_confirm_key, user_last_search, user_warnings, user_last_warning, user_login_attempts, user_inactive_reason, user_inactive_time, user_posts, user_lang, user_timezone, user_dst, user_dateformat, user_style, user_rank, user_colour, user_new_privmsg, user_unread_privmsg, user_last_privmsg, user_message_rules, user_full_folder, user_emailtime, user_topic_show_days, user_topic_sortby_type, user_topic_sortby_dir, user_post_show_days, user_post_sortby_type, user_post_sortby_dir, user_notify, user_notify_pm, user_notify_type, user_allow_pm, user_allow_viewonline, user_allow_viewemail, user_allow_massemail, user_options, user_avatar, user_avatar_type, user_avatar_width, user_avatar_height, user_sig, user_sig_bbcode_uid, user_sig_bbcode_bitfield, user_from, user_icq, user_aim, user_yim, user_msnm, user_jabber, user_website, user_occ, user_interests, user_actkey, user_newpasswd, user_form_salt) SELECT user_id, user_type, group_id, user_permissions, user_perm_from, user_ip, user_regdate, username, username_clean, user_password, user_passchg, user_pass_convert, user_email, user_email_hash, user_birthday, user_lastvisit, user_lastmark, user_lastpost_time, user_lastpage, user_last_confirm_key, user_last_search, user_warnings, user_last_warning, user_login_attempts, user_inactive_reason, user_inactive_time, user_posts, user_lang, user_timezone, user_dst, user_dateformat, user_style, user_rank, user_colour, user_new_privmsg, user_unread_privmsg, user_last_privmsg, user_message_rules, user_full_folder, user_emailtime, user_topic_show_days, user_topic_sortby_type, user_topic_sortby_dir, user_post_show_days, user_post_sortby_type, user_post_sortby_dir, user_notify, user_notify_pm, user_notify_type, user_allow_pm, user_allow_viewonline, user_allow_viewemail, user_allow_massemail, user_options, user_avatar, user_avatar_type, user_avatar_width, user_avatar_height, user_sig, user_sig_bbcode_uid, user_sig_bbcode_bitfield, user_from, user_icq, user_aim, user_yim, user_msnm, user_jabber, user_website, user_occ, user_interests, user_actkey, user_newpasswd, user_form_salt from phpbb_users_2 where user_id_old is null;")





#---------------------------------privmsgs-----------------------------------------------------------------

   #see stored routine file    for instruction          







#----------------forums-------------------------------------------------------------------------------------
#get usercount`
cursor.execute("SELECT max( forum_id ) FROM phpbb_forums;")
data = cursor.fetchone()
maxforum=data
print "maxforum : %s " % maxforum
cursor.execute("SELECT max( right_id ) FROM phpbb_forums;")
data = cursor.fetchone()
maxright=data
print "maxright : %s " % maxright

# remove the auto increment attribute and primary key index    againnnn
cursor.execute("ALTER TABLE phpbb_forums_2 CHANGE `forum_id` `forum_id` MEDIUMINT( 8 ) UNSIGNED NOT NULL;")
cursor.execute("alter table phpbb_forums_2 drop primary key;")

# update users in forums2 with new incremented ids
print "updating ids, again"
cursor.execute("update phpbb_forums_2 set forum_id = forum_id + %s;" % maxforum)
cursor.execute("update phpbb_forums_2 set right_id = right_id + %s;" % maxright)
cursor.execute("update phpbb_forums_2 set left_id = left_id + %s;" % maxright) #right left whats the diff . olol
#^^^^^ but really dont mess with this little section or the forums will break hard . 
#things turning into subtopics of other things or outright dissapearing lolol

#increase non parent ids
cursor.execute("update phpbb_forums_2 set parent_id = parent_id + %s where parent_id <> 0;" % maxforum)

#update related tables
cursor.execute("update phpbb_topics_2 set forum_id = forum_id + %s;" % maxforum)
cursor.execute("update phpbb_posts_2 set forum_id = forum_id + %s;" % maxforum)

#----------------topics-------------------------------------------------------------------------------------
cursor.execute("SELECT max( topic_id ) FROM phpbb_topics;")
data = cursor.fetchone()
maxtopic=data
print "maxtopic : %s " % maxtopic

# remove the auto increment attribute and primary key index    againnnn
cursor.execute("ALTER TABLE phpbb_topics_2 CHANGE `topic_id` `topic_id` MEDIUMINT( 8 ) UNSIGNED NOT NULL;")
cursor.execute("alter table phpbb_topics_2 drop primary key;")

#update related tables again
cursor.execute("update phpbb_topics_2 set topic_id = topic_id + %s;" % maxtopic)
cursor.execute("update phpbb_posts_2 set topic_id = topic_id + %s;" % maxtopic)
cursor.execute("update phpbb_attachments_2 set topic_id = topic_id + %s;" % maxtopic)
cursor.execute("update phpbb_poll_options_2 set topic_id = topic_id + %s;" % maxtopic)
cursor.execute("update phpbb_poll_votes_2 set topic_id = topic_id + %s;" % maxtopic)

#----------------posts_-------------------------------------------------------------------------------------
cursor.execute("SELECT max( post_id ) FROM phpbb_posts;")
data = cursor.fetchone()
maxpost=data
print "maxpost : %s " % maxpost

# remove the auto increment attribute and primary key index    yet again
cursor.execute("ALTER TABLE phpbb_posts_2 CHANGE `post_id` `post_id` MEDIUMINT( 8 ) UNSIGNED NOT NULL;")
cursor.execute("alter table phpbb_posts_2 drop primary key;")

#update related tables yet again
cursor.execute("update phpbb_posts_2 set post_id = post_id + %s;" % maxpost)
cursor.execute("update phpbb_forums_2 set forum_last_post_id = forum_last_post_id + %s;" % maxpost)
cursor.execute("update phpbb_topics_2 set topic_first_post_id = topic_first_post_id +%s;" % maxpost)
cursor.execute("update phpbb_topics_2 set topic_last_post_id = topic_last_post_id + %s;" % maxpost)
cursor.execute("update phpbb_attachments_2 set post_msg_id= post_msg_id + %s;" % maxpost)

#----------------attachments_---------------------------------------------------------------------------------
cursor.execute("SELECT max( attach_id ) FROM phpbb_attachments;")
data = cursor.fetchone()
maxattach=data
print "maxattach : %s " % maxattach

cursor.execute("update phpbb_attachments_2 set attach_id = attach_id + %s;" % maxattach)
#cursor.execute("update phpbb_attachments_2 set post_msg_id= post_msg_id + %s;" % maxpost)
#cursor.execute("update phpbb_attachments_2 set topic_id = topic_id + %s;" % maxtopic)
#cursor.execute("update phpbb_attachments_2 set poster_id = poster_id + %s;" % maxuser)

#------------------merge--------------------------------------------------------------------------------------
print "time for the real deal!"
print "merging forums!" . 
cursor.execute("INSERT INTO phpbb_forums (forum_id, parent_id, left_id, right_id, forum_parents, forum_name, forum_desc, forum_desc_bitfield, forum_desc_options, forum_desc_uid, forum_link, forum_password, forum_style, forum_image, forum_rules, forum_rules_link, forum_rules_bitfield, forum_rules_options,forum_rules_uid, forum_topics_per_page, forum_type, forum_status, forum_posts, forum_topics, forum_topics_real, forum_last_post_id, forum_last_poster_id, forum_last_post_subject, forum_last_post_time, forum_last_poster_name, forum_last_poster_colour, forum_flags, forum_options, display_subforum_list, display_on_index, enable_indexing, enable_icons, enable_prune, prune_next, prune_days, prune_viewed, prune_freq) SELECT forum_id, parent_id, left_id, right_id, forum_parents, forum_name, forum_desc, forum_desc_bitfield, forum_desc_options, forum_desc_uid, forum_link, forum_password, forum_style, forum_image, forum_rules, forum_rules_link, forum_rules_bitfield, forum_rules_options, forum_rules_uid, forum_topics_per_page, forum_type, forum_status, forum_posts, forum_topics, forum_topics_real, forum_last_post_id, forum_last_poster_id, forum_last_post_subject, forum_last_post_time, forum_last_poster_name, forum_last_poster_colour, forum_flags, forum_options, display_subforum_list, display_on_index, enable_indexing, enable_icons, enable_prune, prune_next, prune_days, prune_viewed, prune_freq from phpbb_forums_2;")

#bruder torgen said there wa ssome unspecified issue with a colum here he coudlnt rememebr
print "merging topics!"
cursor.execute("INSERT INTO phpbb_topics (topic_id, forum_id, icon_id, topic_attachment, topic_approved, topic_reported, topic_title, topic_poster, topic_time, topic_time_limit, topic_views, topic_replies, topic_replies_real, topic_status, topic_type, topic_first_post_id, topic_first_poster_name, topic_first_poster_colour, topic_last_post_id, topic_last_poster_id, topic_last_poster_name, topic_last_poster_colour, topic_last_post_subject, topic_last_post_time, topic_last_view_time, topic_moved_id, topic_bumped, topic_bumper, poll_title, poll_start, poll_length, poll_max_options, poll_last_vote, poll_vote_change) SELECT topic_id, forum_id, icon_id, topic_attachment, topic_approved, topic_reported, topic_title, topic_poster, topic_time, topic_time_limit, topic_views, topic_replies, topic_replies_real, topic_status, topic_type, topic_first_post_id, topic_first_poster_name, topic_first_poster_colour, topic_last_post_id, topic_last_poster_id, topic_last_poster_name, topic_last_poster_colour, topic_last_post_subject, topic_last_post_time, topic_last_view_time, topic_moved_id, topic_bumped, topic_bumper, poll_title, poll_start, poll_length, poll_max_options, poll_last_vote, poll_vote_change from phpbb_topics_2;")

print "merging posts!"
cursor.execute("INSERT INTO phpbb_posts (post_id, topic_id, forum_id, poster_id, icon_id, poster_ip, post_time, post_approved, post_reported, enable_bbcode, enable_smilies, enable_magic_url, enable_sig, post_username, post_subject, post_text, post_checksum, post_attachment, bbcode_bitfield, bbcode_uid, post_postcount, post_edit_time, post_edit_reason, post_edit_user, post_edit_count, post_edit_locked)SELECT post_id, topic_id, forum_id, poster_id, icon_id, poster_ip, post_time, post_approved, post_reported, enable_bbcode, enable_smilies, enable_magic_url, enable_sig, post_username, post_subject, post_text, post_checksum, post_attachment, bbcode_bitfield, bbcode_uid, post_postcount, post_edit_time,post_edit_reason, post_edit_user, post_edit_count, post_edit_locked from phpbb_posts_2;")

print "merging attachments!"
cursor.execute("INSERT INTO phpbb_attachments (attach_id,post_msg_id,topic_id,in_message,poster_id,is_orphan,physical_filename,real_filename,download_count,attach_comment,extension,mimetype,filesize,filetime,thumbnail) SELECT attach_id,post_msg_id,topic_id,in_message,poster_id,is_orphan,physical_filename,real_filename,download_count,attach_comment,extension,mimetype,filesize,filetime,thumbnail from phpbb_attachments_2;")

print "merging polls!"
cursor.execute("INSERT INTO phpbb_poll_options (poll_option_id,topic_id,poll_option_text,poll_option_total) SELECT poll_option_id,topic_id,poll_option_text,poll_option_total from phpbb_poll_options_2;")
cursor.execute("INSERT INTO phpbb_poll_votes (topic_id,poll_option_id,vote_user_id,vote_user_ip) SELECT topic_id,poll_option_id,vote_user_id,vote_user_ip from phpbb_poll_votes_2;")


#dont forget to commit
db.commit()

# disconnect
db.close()




