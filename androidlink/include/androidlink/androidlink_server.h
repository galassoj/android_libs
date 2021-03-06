/*
 * Copyright (C) 2012 Simon Lynen, Autonomous Systems Lab ETH Zürich
 *
 * All rights reserved.
 *
 * simon.lynen@mavt.ethz.ch
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Autonomous Systems Lab, ETH Zurich nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ANDROIDLINK_SERVER_H
#define ANDROIDLINK_SERVER_H

#include <jni.h>

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/PointStamped.h>
#include <sensor_msgs/Imu.h>
#include <ssf_core/DoubleArrayStamped.h>
#include <ssf_core/SSF_CoreConfig.h>
#include <ssf_core/ext_imu.h>
#include <ssf_core/ext_state.h>
#include <ssf_core/ext_ekf.h>

class AndroidLinkServer 
{
public:
    AndroidLinkServer(boost::asio::io_service& io_service, unsigned port);
    ~AndroidLinkServer();

    struct AndroidLinkServerImpl;

    void publish_pose(geometry_msgs::PoseWithCovarianceStamped& pose);
    void publish_point(geometry_msgs::PointStamped& point);
    void publish_state(ssf_core::DoubleArrayStamped& state);
    void publish_distomeas(geometry_msgs::PointStamped& point);
    void publish_plane(geometry_msgs::PointStamped& point, geometry_msgs::PointStamped& normal);

private:
    AndroidLinkServer();
    void start_accept();


    boost::scoped_ptr<AndroidLinkServerImpl> d;
};

#endif /* DB_SERVER_H */

