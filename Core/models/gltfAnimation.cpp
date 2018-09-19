#include <gltf.hpp>

glm::mat4   lerpVec3(glm::vec3 start, glm::vec3 end, float lowTime, float highTime, float currTime,
                     int trans)
{
	glm::mat4 mat;
	float percent = (currTime - lowTime) / (highTime - lowTime);

	glm::vec3 res = start + (percent * (end - start));
	if (trans == SCALE)
		return glm::scale(mat, res);
	return glm::translate(mat, res);
}

glm::mat4   lerpQuat(glm::quat start, glm::quat end, float lowTime, float highTime, float currTime)
{
	glm::mat4 mat;
	float percent = (currTime - lowTime) / (highTime - lowTime);

	return glm::toMat4(glm::slerp(start, end, percent));
}

namespace Zion
{
	bool Gltf::_calcAnimation(tinygltf::Animation &anime, float time)
	{
		for (tinygltf::AnimationChannel& chan : anime.channels)
		{
			_animeMatrice[chan.target_node] *= _processChanel(chan.target_path,
				anime.samplers[chan.sampler], time);
		}
		return true;
	}

	glm::mat4 Gltf::_processChanel(std::string &type, tinygltf::AnimationSampler &samp, float time)
	{
		tinygltf::Accessor&     input = _model.accessors[samp.input];
		tinygltf::Accessor&     output = _model.accessors[samp.output];
		tinygltf::BufferView&   inBufView = _model.bufferViews[input.bufferView];
		tinygltf::BufferView&   outBufView = _model.bufferViews[output.bufferView];

		auto *frameTimes = (const float *)(&_model.buffers[inBufView.buffer].data[0] + inBufView.byteOffset);
		auto *vec3s = (const glm::vec3 *)(&_model.buffers[outBufView.buffer].data[0] + outBufView.byteOffset);
		auto *quats = (const glm::quat *)(&_model.buffers[outBufView.buffer].data[0] + outBufView.byteOffset);

		auto minTime = (float)input.minValues[0] - frameTimes[0];
		auto maxTime = (float)input.maxValues[0] - frameTimes[0];
		float curr = time;
		if (curr > maxTime)
			curr = fmodf(curr, maxTime);

		for (int i = 0; i < input.count; i++)
		{
			if (frameTimes[i] - frameTimes[0] > curr)
			{
				auto lowerFrameTime = frameTimes[i - 1] - frameTimes[0];
				auto upperFrameTime = frameTimes[i] - frameTimes[0];

				if (type == std::string("translation"))
					return lerpVec3(vec3s[i - 1], vec3s[i], lowerFrameTime, upperFrameTime, curr, TRANS);
				//if (type == std::string("scale"))
				//	return lerpVec3(vec3s[i - 1], vec3s[i], lowerFrameTime, upperFrameTime, curr, SCALE);
				if (type == std::string("rotation"))
					return lerpQuat(quats[i - 1], quats[i], lowerFrameTime, upperFrameTime, curr);
			}
			if (frameTimes[i] + minTime == curr)
			{
				if (type == std::string("translation"))
					return glm::translate(glm::mat4(), vec3s[i]);
				//if (type == std::string("scale"))
				//	return glm::scale(glm::mat4(), vec3s[i]);
				//if (type == std::string("rotation"))
				//	return glm::toMat4(quats[i]);
			}
		}
		return glm::mat4();
	}
}