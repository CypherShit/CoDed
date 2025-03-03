#include <benchmark/benchmark.h>
#include <core/decoder/decoder.h>
#include <core/encoder/encoder.h>
#include <impl/caesar/caesar_algo.h>
#include <impl/playfair/playfair_algo.h>
#include <impl/rc4/rc4_algo.h>
#include <impl/viginer/viginer_algo.h>
#include <impl/vernam/vernam_algo.h>
#include <impl/atbash/atbash_algo.h>
#include <impl/trithemius/trithemius_algo.h>
#include <gperftools/malloc_extension.h>
#include <iostream>
#include "helper.h"

const std::string input = genString(100);

void reportMemoryUsage() {
    size_t allocated_bytes = 0;
    MallocExtension::instance()->GetNumericProperty("generic.current_allocated_bytes", &allocated_bytes);
    std::cout << "Current allocated bytes: " << allocated_bytes << std::endl;
}

static void BM_CaesarCipher_Encode_Mem(benchmark::State &state) {
    coded::impl::caesar::CaesarCipherAlgo algo(10);
    const core::Encoder &encoder = algo.GetEncoder();
    for (auto _ : state) {
        encoder.Encode(input);
    }
    reportMemoryUsage();
}

BENCHMARK(BM_CaesarCipher_Encode_Mem);

static void BM_CaesarCipher_Decode_Mem(benchmark::State &state) {
    coded::impl::caesar::CaesarCipherAlgo algo(10);
    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    std::string encoded = encoder.Encode(input);
    for (auto _ : state) {
        decoder.Decode(encoded);
    }
    reportMemoryUsage();
}

BENCHMARK(BM_CaesarCipher_Decode_Mem);

// Playfair
static void BM_PlayfairCipher_Encode_Mem(benchmark::State &state) {
    coded::impl::playfair::PlayfairCipherAlgo algo;
    algo.genSalt();

    const core::Encoder &encoder = algo.GetEncoder();

    for (auto _ : state) {
        encoder.Encode(input);
    }
    reportMemoryUsage();
}

BENCHMARK(BM_PlayfairCipher_Encode_Mem);

static void BM_PlayfairCipher_Decode_Mem(benchmark::State &state) {
    coded::impl::playfair::PlayfairCipherAlgo algo;
    algo.genSalt();

    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    std::string encoded = encoder.Encode(input);
    for (auto _ : state) {
        decoder.Decode(encoded);
    }
    reportMemoryUsage();
}

BENCHMARK(BM_PlayfairCipher_Decode_Mem);

// RC4
static void BM_RC4_Encode_Mem(benchmark::State &state) {
    coded::impl::rc4::RC4Algo algo(genString(10));

    const core::Encoder &encoder = algo.GetEncoder();

    for (auto _ : state) {
        encoder.Encode(input);
    }
    reportMemoryUsage();
}

BENCHMARK(BM_RC4_Encode_Mem);

static void BM_RC4_Decode_Mem(benchmark::State &state) {
    coded::impl::rc4::RC4Algo algo(genString(10));

    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    std::string encoded = encoder.Encode(input);
    for (auto _ : state) {
        decoder.Decode(encoded);
    }
    reportMemoryUsage();
}

BENCHMARK(BM_RC4_Decode_Mem);

// Vigenere
static void BM_Vigenere_Encode_Mem(benchmark::State &state) {
    coded::impl::viginer::ViginerAlgo algo(genString(10));

    const core::Encoder &encoder = algo.GetEncoder();

    for (auto _ : state) {
        encoder.Encode(input);
    }
    reportMemoryUsage();
}

BENCHMARK(BM_Vigenere_Encode_Mem);

static void BM_Vigenere_Decode_Mem(benchmark::State &state) {
    coded::impl::viginer::ViginerAlgo algo(genString(10));

    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    std::string encoded = encoder.Encode(input);
    for (auto _ : state) {
        decoder.Decode(encoded);
    }
    reportMemoryUsage();
}

BENCHMARK(BM_Vigenere_Decode_Mem);

// Vernam
static void BM_Vernam_Encode_Mem(benchmark::State &state) {
    coded::impl::vernam::VernamAlgo algo(genString(10));

    const core::Encoder &encoder = algo.GetEncoder();

    for (auto _ : state) {
        encoder.Encode(input);
    }
    reportMemoryUsage();
}

BENCHMARK(BM_Vernam_Encode_Mem);

static void BM_Vernam_Decode_Mem(benchmark::State &state) {
    coded::impl::vernam::VernamAlgo algo(genString(10));

    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    std::string encoded = encoder.Encode(input);
    for (auto _ : state) {
        decoder.Decode(encoded);
    }
    reportMemoryUsage();
}

BENCHMARK(BM_Vernam_Decode_Mem);

// // Atbash
static void BM_Atbash_Encode_Mem(benchmark::State &state) {
    coded::impl::atbash::AtbashCipherAlgo algo;

    const core::Encoder &encoder = algo.GetEncoder();

    for (auto _ : state) {
        encoder.Encode(input);
    }
    reportMemoryUsage();
}

BENCHMARK(BM_Atbash_Encode_Mem);

static void BM_Atbash_Decode_Mem(benchmark::State &state) {
    coded::impl::atbash::AtbashCipherAlgo algo;

    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    std::string encoded = encoder.Encode(input);
    for (auto _ : state) {
        decoder.Decode(encoded);
    }
    reportMemoryUsage();
}

BENCHMARK(BM_Atbash_Decode_Mem);


// // Trithemius
static void BM_Trithemius_Encode_Mem(benchmark::State &state) {
    coded::impl::trithemius::TrithemiusCipherAlgo algo;

    const core::Encoder &encoder = algo.GetEncoder();

    for (auto _ : state) {
        encoder.Encode(input);
    }
    reportMemoryUsage();
}

BENCHMARK(BM_Trithemius_Encode_Mem);

static void BM_Trithemius_Decode_Mem(benchmark::State &state) {
    coded::impl::trithemius::TrithemiusCipherAlgo algo;

    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    std::string encoded = encoder.Encode(input);
    for (auto _ : state) {
        decoder.Decode(encoded);
    }
    reportMemoryUsage();
}

BENCHMARK(BM_Trithemius_Decode_Mem);

